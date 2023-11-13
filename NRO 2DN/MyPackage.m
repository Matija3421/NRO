(* ::Package:: *)

BeginPackage["MyPackage`"]
mccpi[n_]:=Module[{i,x,y,znotraj={},zunaj={}},For[i=1,i<n+1,i++,x=RandomReal[{-1,1}];y=RandomReal[{-1,1}];If[x^2+y^2<=1,AppendTo[znotraj,{x,y}],AppendTo[zunaj,{x,y}]]];StringForm["To\[CHacek]ke znotraj kroga so`` in to\[CHacek]ke zunaj kroga so``.",znotraj,zunaj];Return[{znotraj,zunaj}]];
EndPackage[]
