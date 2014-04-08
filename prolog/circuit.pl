% api for circuit
% signal(terminal, value)
% in(serialno,terminal,gate)
% out(serialno, terminal, gate)
% type(gate,and)


signal(x1,1).
signal(x2,1).
signal(c1,1).


type(g1,xor).
type(g2,and).
type(g3,xor).
type(g4,and).
type(g5,or).	


out(t1,g1).
out(t2,g2).
out(t3,g3).
out(t4,g4).
out(t5,g5).


in(1,x1,g1).
in(2,x2,g1).

in(1,x1,g2).
in(2,x2,g2).

in(1,c1,g3).
in(2,t1,g3).

in(1,c1,g4).
in(2,t1,g4).
	
in(1,t4,g5).
in(2,t2,g5).


signal(T,1) :- out(T,G) , in(S1,Y,G) , signal(Y,1) , type(G,or)
			;  out(T,G) , in(1,X,G) , in(2,Y,G) , signal(Y,1) , signal(X,1), type(G,and)
			;  out(T,G) , in(S1,X,G) , in(S2,Y,G) , signal(Y,1) , signal(X,0), type(G,xor).
			
signal(T,0) :- \+ signal(T,1)
