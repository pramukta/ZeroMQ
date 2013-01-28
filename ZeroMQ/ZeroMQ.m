(* Mathematica Package *)

BeginPackage["ZeroMQ`"]
(* Exported symbols added here with SymbolName::usage *)  

Begin["`Private`"] (* Begin Private Context *) 
	zmqinit = LibraryFunctionLoad["libzmq", "zmq_init", {},  "Void"]
	
End[] (* End Private Context *)

EndPackage[]