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

valid(V1,V2,V3,V4,V5):- equality(V1,V1),equality(V2,V2),equality(V3,V3),equality(V4,V4),equality(V5,V5).

signal(V1, V2, V3, V4, V5, T,1) :- out(T,G) , in(S1,Y,G) , signal(V1, V2, V3, V4, V5, Y,1) , type(G,or),valid(V1,V2,V3,V4,V5)
			;  out(T,G) , in(1,X,G) , in(2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,1), type(G,and),valid(V1,V2,V3,V4,V5)  
			;  out(T,G) , in(S1,X,G) , in(S2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,0), type(G,xor),valid(V1,V2,V3,V4,V5)
			;  out(T,G) , in(1,X,G),  signal(V1, V2, V3, V4, V5, X,0), type(G,not),valid(V1,V2,V2,V3,V4,V5).
			
signal(V1, V2, V3, V4, V5, T,0) :- out(T,G) , in(1,Y1,G), in(2,Y2,G) , signal(V1, V2, V3, V4, V5, Y1,0),signal(V1, V2, V3, V4, V5, Y2,0) , type(G,or),valid(V1,V2,V3,V4,V5)
            ;  out(T,G) , in(1,X,G), signal(V1, V2, V3, V4, V5,X,0), type(G,and),valid(V1,V2,V3,V4,V5)
            ;  out(T,G) , in(2,X,G), signal(V1, V2, V3, V4, V5,X,0), type(G,and),valid(V1,V2,V3,V4,V5)
            ;  out(T,G) , in(1,X,G) , in(2,Y,G) , signal(V1, V2, V3, V4, V5,Y,1) , signal(V1, V2, V3, V4, V5, X,1), type(G,xor),valid(V1,V2,V3,V4,V5)
             ;  out(T,G) , in(1,X,G) , in(2,Y,G) , signal(V1, V2, V3, V4, V5,Y,0) , signal(V1, V2, V3, V4, V5, X,0), type(G,xor),valid(V1,V2,V3,V4,V5)
			;  out(T,G) , in(1,X,G),  signal(V1, V2, V3, V4, V5, X,1), type(G,not),valid(V1,V2,V2,V3,V4,V5).
			
