program lab3;
const n=10;
var
p:array [1..n] of integer;
i:byte;
kol:byte;
begin
writeln('vvedite 10 tselih chisel');
for i:=1 to n do
readln(p[i]);
kol:=0;
for i:=1 to n do
if p[i]>0 then
if p[i] mod 3 = 0 then
kol:=kol+1;
writeln('kolichestvo = ',kol);
readln;
end.