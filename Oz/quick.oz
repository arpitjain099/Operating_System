Mozart Compiler 1.4.0 (20110908185330) playing Oz 3

declare T in
fun{Length L}
   case L of nil then 0 else 1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length T}

%********************** static analysis error *******************
%**
%** unification error in needed statement
%**
%** First value:  <P/2 Length>
%** Second value: <P/2>
%** in file "Oz", line 2, column 0

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          1
%** Expected:             2
%** Application (names):  {Length T}
%** Application (values): {<P/2 Length> 2|65|7|_<optimized>}
%** in file "Oz", line 7, column 0
%** ------------------ rejected (2 errors)
declare T in
fun{Length L}
   case L of nil then 0 else 1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length T P}

%********************* binding analysis error *******************
%**
%** variable P not introduced
%**
%** in file "Oz", line 7, column 10
%** ------------------ rejected (1 error)
declare T P in
fun{Length L}
   case L of nil then 0 else 1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length T P}

%********************** static analysis error *******************
%**
%** unification error in needed statement
%**
%** First value:  <P/2 Length>
%** Second value: <P/2>
%** in file "Oz", line 2, column 0
%** ------------------ rejected (1 error)
declare T P in
fun{Length L}
   case L of nil then 0
   [] then 
      1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length T P}

%*************************** parse error ************************
%**
%** syntax error, unexpected T_then
%**
%** in file "Oz", line 4, column 6
%** ------------------ rejected (1 error)
declare T P in
fun{Length L}
   case L of nil then 0
   [] then 
      1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length 1|5|6}

%*************************** parse error ************************
%**
%** syntax error, unexpected T_then
%**
%** in file "Oz", line 4, column 6
%** ------------------ rejected (1 error)
declare T P in
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length 1|5|6}

%********************** static analysis error *******************
%**
%** unification error in needed statement
%**
%** First value:  <P/2 Length>
%** Second value: <P/2>
%** in file "Oz", line 2, column 0

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          1
%** Expected:             2
%** Application (names):  {Length _}
%** Application (values): {<P/2 Length> 1|5|6}
%** in file "Oz", line 8, column 0
%** ------------------ rejected (2 errors)
declare T P in
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length {1|5|6}}

%********************** static analysis error *******************
%**
%** unification error in needed statement
%**
%** First value:  <P/2 Length>
%** Second value: <P/2>
%** in file "Oz", line 2, column 0

%********************** static analysis error *******************
%**
%** applying non-procedure and non-object
%**
%** Value found: 1|5|6
%** in file "Oz", line 8, column 8

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          1
%** Expected:             2
%** Application (names):  {Length _}
%** Application (values): {<P/2 Length> _<optimized>}
%** in file "Oz", line 8, column 0
%** ------------------ rejected (3 errors)
declare T P in
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length  1|5|6}

%********************** static analysis error *******************
%**
%** unification error in needed statement
%**
%** First value:  <P/2 Length>
%** Second value: <P/2>
%** in file "Oz", line 2, column 0

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          1
%** Expected:             2
%** Application (names):  {Length _}
%** Application (values): {<P/2 Length> 1|5|6}
%** in file "Oz", line 8, column 0
%** ------------------ rejected (2 errors)
declare T P in
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8
{Length  T    }

%********************** static analysis error *******************
%**
%** unification error in needed statement
%**
%** First value:  <P/2 Length>
%** Second value: <P/2>
%** in file "Oz", line 2, column 0

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          1
%** Expected:             2
%** Application (names):  {Length T}
%** Application (values): {<P/2 Length> 2|65|7|_<optimized>}
%** in file "Oz", line 8, column 0
%** ------------------ rejected (2 errors)
declare T P in
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T    }

%********************** static analysis error *******************
%**
%** unification error in needed statement
%**
%** First value:  <P/2 Length>
%** Second value: <P/2>
%** in file "Oz", line 2, column 0

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          1
%** Expected:             2
%** Application (names):  {Length T}
%** Application (values): {<P/2 Length> 2|65|7|_<optimized>}
%** in file "Oz", line 8, column 0
%** ------------------ rejected (2 errors)
declare T P in
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}

%********************* binding analysis error *******************
%**
%** variable O not introduced
%**
%** in file "Oz", line 8, column 13
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse O}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse O}
{Browse T}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface T M}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Q in
{Cross X Y Q}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )

%********************* binding analysis error *******************
%**
%** variable M not introduced
%**
%** in file "Oz", line 22, column 32
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Q in
{Cross X Y Q}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Q: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Q in
{Cross X Y Q}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Q: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Q in
{Cross X Y Q}
{Browse Q}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Q: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare X in
{Cross X Y X}
{Browse X}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  X: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare X in
{Cross X Y X}
{Browse X}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  X: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H}|{Accumulate T Binop Id}
      end
   end
end
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%******************** binding analysis warning ******************
%**
%** local variable Product used only once
%**
%** in file "Oz", line 34, column 17
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H}|{Accumulate T Binop Id}
      end
   end
{Browse {Accumulate [1 2 4] Product 1}}
end
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H}|{Accumulate T Binop Id}
      end
   end
{Browse {Accumulate [1 2 4] Product 1}}
end
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H}|{Accumulate T Binop Id}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H}|{Accumulate T Binop Id}
      end
   end
end
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%******************** binding analysis warning ******************
%**
%** local variable Product used only once
%**
%** in file "Oz", line 34, column 17
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse FoldR {Map [1 2 4] fun{$ X}X*X end}
 fun{$ X Y}X+Y end 0}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          4
%** Expected:             1
%** Application (names):  {Browse FoldR _ _ _}
%** Application (values): {<P/1 Browse> <P/4 FoldR> _<optimized> <P/3> 0}
%** in file "Oz", line 45, column 0
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse FoldR {Map [1 2 4] fun{$ X}X*X end}
 fun{$ X Y}X+Y end 0}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          4
%** Expected:             1
%** Application (names):  {Browse FoldR _ _ _}
%** Application (values): {<P/1 Browse> <P/4 FoldR> _<optimized> <P/3> 0}
%** in file "Oz", line 45, column 0
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse FoldR {Map [1 2 4] fun{$ X}X*X end
 fun{$ X Y}X+Y end 0}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          5
%** Expected:             3
%** Application (names):  {Map _ _ _ _ _}
%** Application (values): {<P/3 Map> [1 2 4] <P/2> <P/3> 0 _<optimized>}
%** in file "Oz", line 45, column 14

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          2
%** Expected:             1
%** Application (names):  {Browse FoldR _}
%** Application (values): {<P/1 Browse> <P/4 FoldR> _<optimized>}
%** in file "Oz", line 45, column 0
%** ------------------ rejected (2 errors)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse FoldR {Map [1 2 4] fun{$ X}X*X end}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          2
%** Expected:             1
%** Application (names):  {Browse FoldR _}
%** Application (values): {<P/1 Browse> <P/4 FoldR> _<optimized>}
%** in file "Oz", line 45, column 0
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse FoldR{Map [1 2 4] fun{$ X}X*X end}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          2
%** Expected:             1
%** Application (names):  {Browse FoldR _}
%** Application (values): {<P/1 Browse> <P/4 FoldR> _<optimized>}
%** in file "Oz", line 45, column 0
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X*X end}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Product {Browse {Map [1 2 4] fun{$ X}X+X end}}}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************* binding analysis error *******************
%**
%** variable Product not introduced
%**
%** in file "Oz", line 45, column 9
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Browse {Map [1 2 4] fun{$ X}X+X end}}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          2
%** Expected:             1
%** Application (names):  {Browse _ _}
%** Application (values): {<P/1 Browse> _<optimized> _<optimized>}
%** in file "Oz", line 45, column 8
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Browse {Map [1 2 4] fun{$ X}X+X end}}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************** static analysis error *******************
%**
%** illegal arity in application
%**
%** Arity found:          2
%** Expected:             1
%** Application (names):  {Browse _ _}
%** Application (values): {<P/1 Browse> _<optimized> _<optimized>}
%** in file "Oz", line 45, column 8
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
{Browse {FoldR {Map [1 2 4]fun{$ X} X*X end} fun {$ X Y} X+Y end 0}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
{Browse {FoldR {Map [1 2 3]fun{$ X} X*X end} fun {$ X Y} X+Y end 0}}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
{Browse {FoldR {Map [1 2 3]fun{$ X} X*X end} fun {$ X Y} X+Y end 0}}
{Browse 'final!'}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
{Browse {FoldR {Map [1 2 3]fun{$ X} X*X end} fun {$ X Y} X+Y end 0}}
{Browse final!}

%*************************** parse error ************************
%**
%** syntax error, unexpected '}', expecting T_VARIABLE
%**
%** in file "Oz", line 47, column 14
%** ------------------ rejected (1 error)
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
{Browse {FoldR {Map [1 2 3]fun{$ X} X*X end} fun {$ X Y} X+Y end 0}}
{Browse "final!"}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
{Browse {FoldR {Map [1 2 3]fun{$ X} X*X end} fun {$ X Y} X+Y end 0}}
{Browse 'final!'}
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )
Declared variables:
  Res: value
% -------------------- accepted
declare T P O 
fun{Length L}
   case L of nil then 0
      else 1+{Length L.2}
   end
end
T=2|65|7|2|8|nil
{Length  T   O}
{Browse T}
declare X Y Res
fun{Concat L M}
   case L of nil then M
   [] H|T then  H|{Concat T M}
   end
end
X=1|2|3|nil
Y=4|6|5|nil
{Concat X Y Res}
{Browse Res}
fun {Preface E L}
   case L of nil then nil
   [] H|T then [E H]|{Preface E T}
   end
end
fun {Cross L M}
   case L of nil then nil
   []H|T then {Concat {Preface H M}{Cross T M}}
   end
end
declare Res in
{Cross X Y Res}
{Browse Res}
{Browse 'gogo bhaag'}
local Accumulate Product in
   fun {Product X Y}
      X*Y
   end
   fun {Accumulate L Binop  Id}
      case L of nil then Id
      []H|T then {Binop H  {Accumulate T Binop Id}}
      end
   end
   {Browse {Accumulate [1 2 4] Product 1}}
end
{Browse {Map [1 2 4] fun{$ X}X+X end}}
{Browse {FoldR {Map [1 2 3]fun{$ X} X*X end} fun {$ X Y} X+Y end 0}}
{Browse 'final!'}
proc {Partition Xs Pivot Left Right}
   case Xs of X|Xr then if
			   X<Pivot then Ln in
			   Left=X|Ln
			   {Partition Xr Pivot Ln Right}
			else Rn in
			   Right=X|Rn
			   {Partition Xr Pivot Left Rn}
			end
   []nil then Left=nil Right=nil
   end
end
fun lazy {Lquicksort Xs}
   case Xs of X|Xr then Left Right Sortedleft Sortedright in
      {Partition Left Right}
      {LAppend {Lquicksort Left} X {Lquicksort Right}}
   [] nil then nil
   end
end
Declared variables:
  Length: procedure/2
  O: value
  P: value
  T: '|'( char '|'( char '|'( char cons ) ) )
Declared variables:
  Concat: procedure/3
  Cross: procedure/3
  Preface: procedure/3
  Res: value
  X: '|'( char '|'( char '|'( char nilAtom ) ) )
  Y: '|'( char '|'( char '|'( char nilAtom ) ) )

%********************* binding analysis error *******************
%**
%** variable Partition not introduced
%**
%** in file "Oz", line 48, column 6

%********************* binding analysis error *******************
%**
%** variable Lquicksort not introduced
%**
%** in file "Oz", line 60, column 10

%********************* binding analysis error *******************
%**
%** variable LAppend not introduced
%**
%** in file "Oz", line 63, column 7
%** ------------------ rejected (3 errors)
