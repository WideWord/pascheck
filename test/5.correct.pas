function NOD(a,b: integer): integer;
begin
  while b<>0 do
  begin
    var c := a mod b;
    a := b;
    b := c;
  end;
  Result := a;
end;
 
var x,y: integer;
 
begin
  x := 15; y := 12;
  writelnFormat('НОД чисел {0} и {1} равен {2}',x,y,NOD(x,y));
  x := 144; y := 64;
  writelnFormat('НОД чисел {0} и {1} равен {2}',x,y,NOD(x,y));
  x := 99; y := 54;
  writelnFormat('НОД чисел {0} и {1} равен {2}',x,y,NOD(x,y));
end.