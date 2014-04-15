% api for circuit
% signal(terminal, value)
% in(serialno,terminal,gate)
% out(serialno, terminal, gate)
% type(gate,and)

equality(0,0).
equality(1,1).

signal(V1, V2, V3, V4, V5, X, Y) :- X = a, equality(V1,Y)
								  ; X = b, equality(V2,Y)
								  ; X = c, equality(V3,Y)
								  ; X = d, equality(V4,Y)
								  ; X = e, equality(V5,Y). 
 

type(g0,and).
in(1,e,g0).
in(2,d,g0).
out(t0,g0).
type(g1,and).
in(1,t0,g1).
in(2,c,g1).
out(t1,g1).
type(g2,and).
in(1,t1,g2).
in(2,b,g2).
out(t2,g2).
type(g3,and).
in(1,e,g3).
in(2,d,g3).
out(t3,g3).
type(g4,and).
in(1,t3,g4).
in(2,c,g4).
out(t4,g4).
type(g5,and).
in(1,e,g5).
in(2,d,g5).
out(t5,g5).
type(g6,or).
in(1,e,g6).
in(2,d,g6).
out(t6,g6).
type(g7,and).
in(1,t6,g7).
in(2,c,g7).
out(t7,g7).
type(g8,or).
in(1,t5,g8).
in(2,t7,g8).
out(t8,g8).
type(g9,and).
in(1,t8,g9).
in(2,b,g9).
out(t9,g9).
type(g10,or).
in(1,t4,g10).
in(2,t9,g10).
out(t10,g10).
type(g11,and).
in(1,t10,g11).
in(2,a,g11).
out(t11,g11).
type(g12,or).
in(1,t2,g12).
in(2,t11,g12).
out(t12,g12).

valid(V1,V2,V3,V4,V5):- equality(V1,V1),equality(V2,V2),equality(V3,V3),equality(V4,V4),equality(V5,V5).

signal(V1, V2, V3, V4, V5, T,1) :- out(T,G) , in(S1,Y,G) , signal(V1, V2, V3, V4, V5, Y,1) , type(G,or),valid(V1,V2,V3,V4,V5)
			;  out(T,G) , in(1,X,G) , in(2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,1), type(G,and),valid(V1,V2,V3,V4,V5)  
			;  out(T,G) , in(S1,X,G) , in(S2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,0), type(G,xor),valid(V1,V2,V3,V4,V5)
			;  out(T,G) , in(1,X,G),  signal(V1, V2, V3, V4, V5, X,0), type(G,not),valid(V1,V2,V2,V3,V4,V5).
			
signal(V1, V2, V3, V4, V5, T,0) :- \+ signal(V1, V2, V3, V4, V5, T, 1).
