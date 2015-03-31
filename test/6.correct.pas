function Power(a: real; n: integer): real;
begin
  Result := 1;
  for var i:=1 to n do
    Result *= a;
end;
 
var 
  a: real; 
  n: integer;   
 
begin
  write('Введите a: ');
  readln(a);
  write('Введите n: ');
  readln(n);
  writelnFormat('{0} в степени {1} = {2}',a,n,Power(a,n));  
end.
