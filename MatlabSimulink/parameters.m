clc; clear;

%% Parameterskript - Elektronische Drosselvorrichtung
%  PID-Regelung
% open_system('MiL_PID')

% Simulationsparameter
TSample = 1e-3;%2e-3;                                 % Zykluszeit für RCP und MiL [s]


% Motorkonstanten
UB = 15;                                        % Betriebsspannung in V
RA = 2.579624359;                               % Ankerwiderstand [Ohm]
LA = 0.001665974;                               % Ankerinduktivität [H]
cn = 30.41688361;                               % Drehzahlkonstante [(rad/s)/V]
cM = 1/cn;                                      % Drehmomentkonstante [Nm/A]


% Mechanische Parameter
iG = 18.125;                                    % Getriebegesamtübersetzung [1]

phimin = 0;                                     % Minimaler Drehwinkel [rad]
phimax = pi/2;                                  % Maximaler Drehwinkel [rad]
phi0 = 0.1063;%0.1095;%0.1150;%0.1187;                                  % Drehwinkel in Ruhelage [rad]

Jges = 1.359e-3;                                % Reduziertes Massenträgheitsmoment [kgm^2]

MFv = 0.4976;                                   % Vorspannmoment des Federsystems [Nm]
cF = 0.0640;                                    % Federkonstante der Drehfeder [Nm/rad]
phi30 = 1e-3;                                   % Fitparameter des Federvorspannmoments [rad]

% cV = 0;                                       % Koeffizient des viskosen Reibmomentanteils [Nms/rad]
MH = 0.1705;                                    % Haftreibmoment [Nm]
phip30 = 1e-1;                                  % Fitparameter der Haftreibung [rad/s]


% Sensorparameter
phiminV = 0.5330;%0.5127;                               % Sensorspannung bei minimalem Drehwinkel (gemessen) [V]
phimaxV = 4.415;%4.5667;                               % Sensorspannung bei maximalem Drehwinkel (gemessen) [V]
cphi    = (phimax-phimin)/(phimaxV-phiminV);    % Sensorkonstante Drehwinkelsensor [rad/V]

cADC = (5/65535)*cphi;                           % Quantisierungskonstante des ADC [(V/step)*(rad/V) = rad/step]
TADC = TSample;                                 % Totzeit des ADC [s]
TMedian5 = 3*TSample;                           % Totzeit des Medianfilters [s]
TSensor  = TADC+TMedian5;                       % Totzeit des Drehwinkelsensors [s]


% Parameter Leistungselektronik
nPWM = 255;                                     % Anzahl der PWM-Schritte
cPWM = UB/nPWM;                                 % Quantisierungskonstante der H-Brücke


% Streckenparameter
a = Jges/cF;
b = (cM*iG)^2/(cF*RA);
T_DK1 = b/2 + sqrt(b^2/4-a);                    % Zeitkonstante der Drosselklappe T1
T_DK2 = b-T_DK1;                                % Zeitkonstante der Drosselklappe T2
K_DK  = cM*iG/(cF*RA);                          % Streckenverstärkung der Drosselklappe


% Reglerparameter des diskreten PID-Reglers
P=29.8794;
I=0.4644;
D=0.0103;
N=358.8259;


% % Laden der Trajektorie phi3_ref der Lookup Table
% % Trainings-Set = 1; Test-Set = 2
% mode = 1;
% if mode == 1
%     load('DK_Trainings_Set.mat','A','Length','Tinterval')
% elseif mode == 2
%     load('DK_Test_Set.mat','A','Length','Tinterval')
% end

% time = 0:Tinterval:(Length-1)*Tinterval;        % Zeitachse der Trajektorie
% offset = 0.5;
% phi3 = (A-offset)*cphi;                         % Korrektur der gemessenen Daten
% TSim = 49.98;                                   % Simulationsdauer bei Anwendung der Trajektorien




%% Fahrzeuglängsdynamik

% Drehmomentkennlinie - Volllast
n_Mot = [1    2     3     4     5     6     6.5  ]*1000;
M_Mot = [145.0 161.0 181.0 194.0 188.0 170.0 158.5];

eta = 0.95;             % Antriebsstrangwirkungsgrad (Skript Dorsch)

iG_car = [0.01 3.682 2.002 1.330 1.000 0.805];                % Übersetzungen Schonganggetriebe (vorwärts)
iG_car = [0.001 3.682 2.002 1.330 1.000 0.805];                % Übersetzungen Schonganggetriebe (vorwärts)
iG_car_temp = [0.0 3.682 2.002 1.330 1.000 0.805];                % Übersetzungen Schonganggetriebe (vorwärts)
iD_car = 3.45;                                           % Übersetzung Differentialgetriebe 323i

iG_car_up = single([1.2*iG_car(2), 1.2*iG_car(3), 1.1*iG_car(4), 1.1*iG_car(5), 1.1*iG_car(6)]);
iG_car_low = single([0.8*iG_car(2), 0.8*iG_car(3), 0.9*iG_car(4), 0.9*iG_car(5), 0.9*iG_car(6)]);

figure
plot(iG_car(2:6), [1 2 3 4 5], iG_car_up, [1 2 3 4 5], iG_car_low, [1 2 3 4 5])
% plot([1 2 3 4 5], iG_car(2:6), [1 2 3 4 5], iG_car_up, [1 2 3 4 5], iG_car_low)

r_stat = (205*0.55*2+15*25.4)/(2*1000);
r_dyn  = r_stat;

n_Mot_max_1pmin = 4000;       
v_lim_calc_kmh = n_Mot_max_1pmin/60*1./iG_car(2:6)*1/iD_car*2*pi*r_dyn*3.6;    % Schlupf vernachlässigt

a_max = 1;

m_F = 1110;                                                % Leergewicht Fzg.
m_Zu  = 0;                                                   % Zuladung

g = 9.81;
f_R = 0.01;                                                  % Rollwiderstandsbeiwert (Skript Dorsch)

c_W = 0.4;                                                   % Luftwiderstandsbeiwert (BA)
A   = 1.87;                                                  % Windaufstandsfläche (BA)
p_L = 1.225;                                                 % Luftdichte bei 15° C und Normaldruck

e = [1.17 1.04];                                             % Drehmassenzuschlagsfaktor (Skript Dorsch)

v_0 = 130/3.6;

v_ref = 130;

iG_0 = 5;



%% Microcontroller
tsens = 0.05;

Ts_host = 0.05;

Ts_chart = 0.05;

%% Negatives Motormoment
m_vkm = -10/1000;    % Nm/(1/min)
b_vkm = -10;         % Nm

%% Geschwindigkeitssensor
c1_vsens = 3;                                % Anz. Impulse pro Umdrehung
c2_vsens = c1_vsens*iD_car/(2*pi*r_dyn);     % Sensorkonstante Radgeschwindigkeit in Kardanwellendrehzahl [imp/s]
c3_vsens = 0.1;                              % Pulsweite

%% Diskreter Beobachter (nur gültig für gerade Ebene und v>0)
c2_mlf = 0.5*c_W*A*p_L*1/(m_F+m_Zu);
c1_mlf = 0;
c0_mlf = f_R*(m_F+m_Zu)*g*1/(m_F+m_Zu);
c_VKM = iD_car*eta/(r_stat*(m_F+m_Zu));


k1 = 0.5*c_W*A*p_L*1/(m_F+m_Zu);
k2 = 0.0;
k3 = f_R*(m_F+m_Zu)*g*1/(m_F+m_Zu);
k4 = iD_car*eta/(r_stat*(m_F+m_Zu));
k5 = 30*iD_car/(pi*r_dyn);
p = [-5.1168e-6, 0.0518, 1.1411e+2];


%% Acc-Sensor
Ts_acc = 0.1;
i2c_addr_acc = 0x36;
i2c_timeout_acc = 0.01;

%% Velocity-Sensor
reload_value = int32(10000);
T1_vel = 0.1;        % [s]    Zeitbasis Geschwindigkeitsberechnung
T2_vel = 0.01;       % [s]    Zeitbasis Counter-Auswertung
k1_vel = 12*4;       % [1]    12 Impulse pro Umdrehung zzgl. Vierfachauswertung
k2_vel = 762;        % [U/km] Wegstreckenzahl
ks_vel = single(3600/(T1_vel*k1_vel*k2_vel));

k_vel_temp = 10/4*1/iD_car*(2*pi*r_dyn)*3.6   *1/k1_vel*1/T1_vel

% v_rad/(2*pi*r_dyn)*i_diff -> Drehzahl Getriebeausgangswelle
% v_rad/(2*pi*r_dyn)*i_diff*4/10 -> Drehzahl Tachowelle
% n_tacho*10/4*1/i_diff*(2*pi*r_dyn)*3.6 -> Fahrzeuggeschwindigkeit [km/h]


%% Calculation Transfer-Function
xs_lin = 100/3.6;
i_lin = 4;
syms Dx_lin Du_lin s
us_lin = ((k1*xs_lin^2+k2*xs_lin+k3)*1/(k4*iG_car(i_lin+1))-m_vkm*k5*iG_car(i_lin+1)*xs_lin-b_vkm)*1/(p(1)*k5^2*iG_car(i_lin+1)^2*xs_lin^2+p(2)*k5*iG_car(i_lin+1)*xs_lin+p(3));
a0_lin = -(-2*k1*xs_lin-k2+2*k4*iG_car(i_lin+1)^3*p(1)*k5^2*xs_lin*us_lin+k4*iG_car(i_lin+1)^2*p(2)*k5*us_lin+k4*iG_car(i_lin+1)^2*m_vkm*k5);
b_lin = (k4*iG_car(i_lin+1)^3*p(1)*k5^2*xs_lin^2+k4*iG_car(i_lin+1)^2*p(2)*k5*xs_lin+k4*iG_car(i_lin+1)*p(3));
Gs_lin = b/(s+a0_lin);
pretty(Gs_lin);
Gs_lin = tf([b_lin/a0_lin], [1/a0_lin 1]);

K_lin = Gs_lin.Numerator{1}(2);
T_lin = Gs_lin.Denominator{1}(1);

% Kalmanauslegung
Ad = [a0_lin];
Bd = [b_lin];
Cd = [1];
Dd = [0];

Tsd = -1;
sys = ss(Ad,[Bd Bd],Cd,Dd,Tsd,'InputName',{'u' 'w'},'OutputName','y');  % Plant dynamics and additive input noise w

Q = 0.5/3.6;
R = 0.05;

[kalmf,L,~,Mx,Z] = kalman(sys,Q,R);


% Reglerauslegung
% Innerer I-Regler
T_ersatz_lin = 1;%0.5;       % Beschleunigung innerhalb gewünschter "Anstiegszeit" auf 63 %; hier 3 m/s^2 in 0,5 s
K_I_lin = (T_lin/T_ersatz_lin-1)/K_lin;

% Übertragungsfunktion für Beschleunigung
Gs_Beschleunigung_lin = Gs_lin*tf([1 0], [1]);
G_I_lin = tf([K_I_lin], [1 0]);
G_o_I_lin = Gs_Beschleunigung_lin*G_I_lin;
G_w_I_lin = G_o_I_lin/(1+G_o_I_lin);

% Vorfilter für Beschleunigung
V_F_lin = 1/(K_lin*K_I_lin)+1;
G_V_I_lin = V_F_lin*G_w_I_lin;

% P-Regler für Geschwindigkeit
K_P_lin = 0.15;
G_w_a_lin = tf([K_P_lin/(1+K_P_lin)], [T_ersatz_lin/(1+K_P_lin) T_ersatz_lin/(1+K_P_lin) 1]);

T1_lin = -1/(-0.5/T_ersatz_lin + sqrt( (1/T_ersatz_lin)^2/4 - K_P_lin/T_ersatz_lin))
T2_lin = -1/(-0.5/T_ersatz_lin - sqrt( (1/T_ersatz_lin)^2/4 - K_P_lin/T_ersatz_lin))



%% Zustandsrückführung



%% SampleTime ADC
Ts_ADC = 0.001;

%% Fahrpedalsensor
ped_low_deg  = 195.92;
ped_high_deg = 184.57;
ped_m = ped_high_deg - ped_low_deg;

%% Butterworthfilter
% Fahrzeuggeschwindigkeit
fc_butter = 10;                                    % Cut-Off-Frequenz (Hz)
fs_butter = 100;                                   % Samplerate (angelehnt an Beobachter)
Ts_butter = 1/fs_butter;
% [b_num_vFzg, a_den_vFzg] = butter(1,fc_butter/(fs_butter/2));                 % Butterworthfilter über normierte Frequenz
[b_num_vFzg, a_den_vFzg] = butter(4,0.5/(100/2))
[b_num_vFzg, a_den_vFzg] = butter(2,0.5/(100/2))

% Anzeigesignale (Steigung/Beschleunigung)
fc_butter = 1;
fs_butter = 100;
[b_num_stg, a_den_stg] = butter(1,fc_butter/(fs_butter/2));

%% Velocity Profile
vel_profile.Ts = single(0.005);
vel_profile.a_max = single(1.0);
vel_profile.j_max = single(1.0);