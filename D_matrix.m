m=30;
k=6;
M=(0:1:m^k-1);
D=zeros(m^k,m^k);
for i=1:m^k
    for j=1:k
        kd=j-1;
        id=i-1;
        
        D(i,i)=3;
        if mod(floor((id)/m^(kd)),m)==0
            D(i,i+m^kd)=-.5;
            D(i+m^kd,i)=-.5;
     
        elseif mod(floor(((id)+m^(kd))/m^(kd)),m)==0
            D(i,i-m^kd)=-.5;
            D(i-m^kd,i)=-.5;
        
        else
            D(i,i+m^kd)=-0.5;
            D(i,i-m^kd)=-0.5;
            D(i+m^kd,i)=-0.5;
            D(i-m^kd,i)=-0.5;
        end
    end
end
    D=sparse(D);
    length(D)