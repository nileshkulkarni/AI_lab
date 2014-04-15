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
 


type(g0,and).
in(1,e,g0).
in(2,d,g0).
out(t0,g0).
type(g1,and).
in(1,t0,g1).
in(2,c,g1).
out(t1,g1).
type(g2,and).
in(1,e,g2).
in(2,d,g2).
out(t2,g2).
type(g3,or).
in(1,e,g3).
in(2,d,g3).
out(t3,g3).
type(g4,and).
in(1,t3,g4).
in(2,c,g4).
out(t4,g4).
type(g5,or).
in(1,t2,g5).
in(2,t4,g5).
out(t5,g5).
type(g6,and).
in(1,t5,g6).
in(2,b,g6).
out(t6,g6).
type(g7,or).
in(1,t1,g7).
in(2,t6,g7).
out(t7,g7).
type(g8,and).
in(1,e,g8).
in(2,d,g8).
out(t8,g8).
type(g9,or).
in(1,e,g9).
in(2,d,g9).
out(t9,g9).
type(g10,and).
in(1,t9,g10).
in(2,c,g10).
out(t10,g10).
type(g11,or).
in(1,t8,g11).
in(2,t10,g11).
out(t11,g11).
type(g12,or).
in(1,e,g12).
in(2,d,g12).
out(t12,g12).
type(g13,or).
in(1,t12,g13).
in(2,c,g13).
out(t13,g13).
type(g14,and).
in(1,t13,g14).
in(2,b,g14).
out(t14,g14).
type(g15,or).
in(1,t11,g15).
in(2,t14,g15).
out(t15,g15).
type(g16,and).
in(1,t15,g16).
in(2,a,g16).
out(t16,g16).
type(g17,or).
in(1,t7,g17).
in(2,t16,g17).
out(t17,g17).


signal(V1, V2, V3, V4, V5, T,1) :- out(T,G) , in(S1,Y,G) , signal(V1, V2, V3, V4, V5, Y,1) , type(G,or) , !
			;  out(T,G) , in(1,X,G) , in(2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,1), type(G,and) , !
			;  out(T,G) , in(S1,X,G) , in(S2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,0), type(G,xor), !
			;  out(T,G) , in(1,X,G),  signal(V1, V2, V3, V4, V5, X,0), type(G,not).
			
signal(V1, V2, V3, V4, V5, T,0) :- \+ signal(V1, V2, V3, V4, V5, T, 1).
