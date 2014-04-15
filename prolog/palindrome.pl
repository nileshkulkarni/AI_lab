% api for circuit
% signal(terminal, value)
% in(serialno,terminal,gate)
% out(serialno, terminal, gate)
% type(gate,and)


signal(V1, V2, V3, V4, V5, X, Y) :- X = a, V1 is Y 
								  ; X = b, V2 is Y
								  ; X = c, V3 is Y
								  ; X = d, V4 is Y
								  ; X = e, V5 is Y. 
 

type(g0,xor).
in(1,a,g0).
in(2,e,g0).
out(t0,g0).
type(g1,xor).
in(1,b,g1).
in(2,d,g1).
out(t1,g1).
type(g2,or).
in(1,t0,g2).
in(2,t1,g2).
out(t2,g2).
type(g3,not).
in(1,t2,g3).
out(t3,g3).

signal(V1, V2, V3, V4, V5, T,1) :- out(T,G) , in(S1,Y,G) , signal(V1, V2, V3, V4, V5, Y,1) , type(G,or) , !
			;  out(T,G) , in(1,X,G) , in(2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,1), type(G,and) , !
			;  out(T,G) , in(S1,X,G) , in(S2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,0), type(G,xor), !
			;  out(T,G) , in(1,X,G),  signal(V1, V2, V3, V4, V5, X,0), type(G,not).
			
signal(V1, V2, V3, V4, V5, T,0) :- \+ signal(V1, V2, V3, V4, V5, T, 1).
