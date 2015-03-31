function Fib(N: integer): integer;
begin
  if (N=1) or (n=2) then
    Result := 1
  else  
  begin
    var a := 1;
    var b := 1;
    for var i:=3 to N do 
    begin
      Result := a + b;
      a := b;
      b := Result;
    ed;
  end;
end;
 
begin
  writeln(Fib(5));
  writeln(Fib(6));
  writeln(Fib(7));
end.
