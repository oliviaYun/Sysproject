i = 1;
for w = 0.1:0.001:100;
   
k(i)= 1/((w*j)^2 + (0.1*w*j)+1);
i = i+1;
end
w = 0.1:0.001:100;
y = 20*log10(abs(k));
figure(1);
semilogx(w,y);
th = atan(imag(k)./real(k));
figure(2);
semilogx(w,unwrap(th));