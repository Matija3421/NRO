global znotraj_kroga
global znotraj_kvadrata
len = input("Vnesite število želenih naključnih točk: "); % prosi uporabnika za želeno število želenih točk
tiledlayout(2,1);
nexttile
hold on
for i = 1:10:len+1;
    [pi,napaka]=area_pi(i); % kliče funkcijo area_pi z vsakič večjim številom točk od 1 do želenega števila
    plot(i,pi,"g.") % nariše graf z vrednostmi izračunane približne pi
    plot(i,napaka,"r.")% nariše graf odstopka izračunane pi od dejanske
end

yline(pi,"-","dejanska vrednost pi");% nariše vodoravno črto pri vrednosti pi
yline(0); % nariše vodoravno črto pri vrednosti 0
lgd = legend('vrednost izračunane pi','odstopanje od dejanske pi'); % nariše legendo
lgd.Location = "northoutside";
xlabel('število točk'); % ime x osi
ylabel('vrednost pi'); % ime y osi
hold off


nexttile
hold on
krog = @(x) [(1-x.^2).^(1/2);-(1-x.^2).^(1/2)]; % anonimna funkcija, ki za krožnico definira koordinate y glede na x 
sezn = linspace(-1,1,100); % generira 100 točk x od -1 do 1
y = krog(sezn); % za vsako x točko generira točki y pri tem x
plot(sezn,y(1,:),"b-", DisplayName='', HandleVisibility='off'); %nariše zgornjo polovico kroga
plot(sezn,y(2,:),"b-", DisplayName='', HandleVisibility='off'); %nariše spodnjo polovico kroga

plot(znotraj_kroga(:,1),znotraj_kroga(:,2),"g*", DisplayName="točke znotraj kroga");% nariše točke znotraj kroga
plot(znotraj_kvadrata(:,1),znotraj_kvadrata(:,2),"r.", DisplayName="točke zunaj kroga");% nariše točke zunaj kroga
legend(Location='northoutside');%pozicija legende (sredina zgoraj)
xlabel('x os'); %ime osi x
ylabel('y os'); %ime osi y
daspect([1,1,1]);



function[pij,napaka] = area_pi(n) % definiramo funkcijo, ki določi število pi po postopku monte carlo.
global znotraj_kroga
global znotraj_kvadrata
[znotraj_kroga,znotraj_kvadrata] = mcc_pi(n); % kličemo funkcijo mcc_pi in iz nje dobimo točke zunaj in znotraj kroga
m = size(znotraj_kroga);
pij = m(1)/n*4; % izračuna približek števila pi
napaka = pij - pi; % izračuna odstopanje od dejanskega števila pi
end




