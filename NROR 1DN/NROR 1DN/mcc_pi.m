function[znotraj_kroga,znotraj_kvadrata] = mcc_pi(n) %funkcija ki generira naključne točke v kvadratu velikosti 2x2 
seznam1 = -1+2*rand(n);% generira x koordinate       % in določi ali so znotraj kroga polmera 1 ali ne.
seznam2 = -1+2*rand(n);% generira y koordinate
znotraj_kroga = [];
znotraj_kvadrata = [];
for i = 1:n
    if (sqrt(seznam1(i)^2+seznam2(i)^2)) <= 1 %preveri ali je točka oddaljena od izhodišča za manj ali enako 1
        A = [seznam1(i),seznam2(i)];          %in jo doda v seznam točk znotraj kroga, če izpolni te pogoje
        dim = size(znotraj_kroga);
        znotraj_kroga(dim(1)+1,:)= A;
    else
        A = [seznam1(i),seznam2(i)]; %če ne izpolni teh pogojev jo doda v seznam točk zunaj kroga
        dim = size(znotraj_kvadrata);
        znotraj_kvadrata(dim(1)+1,:) = A;
    end
end
%disp("točke znotraj krožnice so")
%disp(znotraj_kroga)
%disp("točke znotraj kvadrata so")
%disp(znotraj_kvadrata)
end