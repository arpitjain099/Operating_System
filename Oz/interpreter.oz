declare Debug = 1
\insert 'Unify.oz'
declare L = [[1 1] [2 2] [3 3]]
declare
proc {Exp L}
   case L
   of nil then skip
   [] [X Y]|_ then {Browse X} {Browse Y}
   else {Browse 'none'}
   end
end


declare
SemanticStack
{Cell.new nil SemanticStack}

declare
proc {Pop ?Statement ?Environment}
   if @SemanticStack == nil then
      Statement = nil
      Environment = envrn()
   else
      semstat(Statement Environment) = @SemanticStack.1
      SemanticStack := @SemanticStack.2
   end
end

declare
proc {Push Statement Environment}
   local IsListOfStatements in
      {List.is Statement.1 ?IsListOfStatements}
      if IsListOfStatements == true then
	 ListOfSemanticStatements = {Map Statement fun {$ S} semstat(S Environment) end} NewSemanticStack in
	 {List.append ListOfSemanticStatements @SemanticStack NewSemanticStack}
	 SemanticStack := NewSemanticStack
      else
	 SemanticStack := semstat(Statement Environment) | @SemanticStack
      end
   end
end

declare
fun {BuildClosure Procedure Environment}
   local BuildContextEnvironment Free ListOfFreeIdentifiers routine|A|[S] = Procedure in
      fun {ListOfFreeIdentifiers L}
	 case L
	 of nil then nil
	 [] [localvar ident(X) S] then
	    {List.filter {ListOfFreeIdentifiers S} fun{$ Y} if Y==X then false else true end end}
	 [] [routine A S] then L Args in
	    Args = {List.map A fun{$ X} case X of ident(Y) then Y else raise invalidArgument(X) end end end }
	    {List.filter {ListOfFreeIdentifiers S}
	     fun{$ Y}
		if {List.member Y Args} == true then false
		else true
		end
	     end
	     ?L}
	    L
	 [] [apply ident(F) Params] then Ret in
	    {List.append [F] {ListOfFreeIdentifiers Params} ?Ret}
	    Ret
	 [] H|T then App in {List.append {ListOfFreeIdentifiers H} {ListOfFreeIdentifiers T} ?App} App
	 %of H#T then {ListOfFreeIdentifiers H}|{ListOfFreeIdentifiers T} According to correction in problem statement, # is no in our language
	 [] ident(Z) then [Z]
	 else nil
	 end
      end
      Free = {ListOfFreeIdentifiers Procedure}
      {Browse Free}
      fun {BuildContextEnvironment F Env}
	 case F
	 of nil then envrn()
	 [] Var|L then
	    if Var == nil then envrn()
	    else CE in
	    {Record.adjoin envrn(Var: Env.Var) {BuildContextEnvironment L Env} ?CE}
	       CE
	    end
	 end
      end
%      {Browse {BuildContextEnvironment Free Environment}}
%               {Browse 'HERE'}
      %Args = {List.map A fun{$ X} case X of ident(Y) then Y else raise invalidArgument(X) end end end }
      %{Browse [routine A S {BuildContextEnvironment Free Environment}]}
      [routine A S {BuildContextEnvironment Free Environment}]
   end
end

   
	    

declare
proc {InterpretNext}
   local Statement Environment in
      if Debug == 1 then DictEntries in
	 {Browse @SemanticStack}
	 {Dictionary.entries SingleAssignmentStore ?DictEntries}
	 {Browse DictEntries}
      end
      {Pop ?Statement ?Environment}
      case Statement
      of nil then {Browse 'Done'}
      [] [nop] then {InterpretNext}
      [] [localvar ident(X) S] then
	 AdjoinedEnvironment in
	 {Record.adjoin Environment envrn(X:{AddKeyToSAS}) AdjoinedEnvironment}
	 {Push S AdjoinedEnvironment}
	 {InterpretNext}
      [] [bind Exp1 Exp2] then
	 case Exp2
	 of routine|_ then
	    case Exp1
	    of ident(X) then {BindValueToKeyInSAS Environment.X {BuildClosure Exp2 Environment}}
	    else raise incompatibleTypes(Exp1 Exp2) end
	    end
	 [] ident(Y) then
	    case Exp1
	    of routine|_ then {BindValueToKeyInSAS Environment.Y {BuildClosure Exp2 Environment}}
	    else {Unify Exp1 Exp2 Environment}
	    end
	 else {Unify Exp1 Exp2 Environment}
	 end
	 {InterpretNext}
      [] [conditional ident(X) S1 S2] then ValX = {RetrieveFromSAS Environment.X} in
	 if  ValX == true then
	    {Push S1 Environment}
	 elseif ValX == false then
	    {Push S2 Environment}
	 else raise identifierNotBoolean(ident(X)) end
	 end
	 {InterpretNext}
      [] [match ident(X) P1 S1 S2] then ValX = {RetrieveFromSAS Environment.X} BuildCaseEnvironment CaseEnvironment in
	 fun {BuildCaseEnvironment Pattern}
	    case Pattern
	    of ident(X) then
	       envrn(X: {AddKeyToSAS})
	    [] record|_|Pairs then Environments in
	       Environments = {Map Pairs.1 fun{$ X} {BuildCaseEnvironment X.2.1} end}
	       %{FoldL Environments fun{$ X Y} local E in {Record.adjoin X Y E} E end end envrn()}
	       {FoldL Environments fun{$ X Y} {Record.adjoin X Y} end envrn()}
	    else envrn()
	    end
	 end
	 {Record.adjoin Environment {BuildCaseEnvironment P1} ?CaseEnvironment}
	 try
	    {Unify P1 ValX CaseEnvironment}
	    {Push S1 CaseEnvironment}
	 catch incompatibleTypes(_ _) then
	    {Push S2 Environment}
	 end
	 {InterpretNext}
      [] apply|ident(F)|Params then Func in
	 
	 Func = {RetrieveFromSAS Environment.F}
	 case Func
	 of routine|Args|S|[CE] then Environments ApplyEnvironment in
	    {List.zip Args Params fun {$ X Y}
			     case X
			     of ident(XX) then
				case Y
				of ident(YY) then AddEnv UnifyEnv in
				   AddEnv = envrn(XX:{AddKeyToSAS})
				   {Record.adjoin AddEnv envrn(YY:Environment.YY) ?UnifyEnv}
				   {Unify X Y UnifyEnv}
				   AddEnv
				else raise invalidArgument(Y) end
				end
			     else raise invalidArgument(X) end
			     end
			  end ?Environments}
%	    {Browse Environments}
%	    {Browse {FoldL Environments fun{$ X Y} {Record.adjoin X Y} end envrn()}}
	    ApplyEnvironment = {Record.adjoin {FoldL Environments fun{$ X Y} {Record.adjoin X Y} end envrn()} CE}
%	    {Browse CE}
%				   {Browse 'Here'}	    
%	    {Browse ApplyEnvironment}
	    {Push S ApplyEnvironment}
	    {InterpretNext}
	 else raise invalidRoutine(Statement) end
	 end
      else raise invalidStatement(Statement) end
      end
   end
end

declare
proc {Start Prog}
   {Push Prog envrn()}
   %if Debug == 1 then {Browse @SemanticStack} end
   {InterpretNext}
end

declare
Program =
[
 [localvar ident(flag)
  [
   [localvar ident(matched)
    [
     [localvar ident(assign)
      [
       [bind ident(assign) [routine
			    [ident(x) ident(y)]
			    [[bind ident(x) literal(10314)]
			     [bind ident(y) literal(41301)]
			     [bind ident(flag) false]
			    ]
			   ]
       ]
       [localvar ident(a)
	[
	 [localvar ident(b)
	  [
	   [localvar ident(x0)
	    [
	     [localvar ident(y0)
	      [
	       [apply ident(assign) ident(x0) ident(y0)]
	       [bind ident(a)
		[record literal(point)
		 [
		  [literal(x) ident(x0)]
		  [literal(y) ident(y0)]
		 ]
		]
	       ]
	       [bind ident(b)
		[record literal(point)
		 [
		  [literal(x) ident(y0)]
		  [literal(y) ident(x0)]
		 ]
		]
	       ]
	       [match ident(a)
		[record literal(point)
		 [
		  [literal(x) ident(xa)]
		  [literal(y) ident(ya)]
		 ]
		] 
		[
		 match ident(b)
		 [record literal(point)
		  [
		   [literal(x) ident(xb)]
		   [literal(y) ident(yb)]
		  ]
		 ] 
		 [bind ident(matched) true]
		 [bind ident(matched) false]
		]
		[bind ident(matched) false]
	       ]
	      ]
	     ]
	    ]
	   ]
	  ]
	 ]
	]
       ]
      ]
     ]
    ]
   ]
  ]
 ]
]
{Start Program}
