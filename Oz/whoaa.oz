declare
fun {Filter P Q}
   case Q
   of nil then nil		%%empty list will return empty list back
   [] L|R andthen {P L} then
      L|{Filter R P}		%%carry the check over the rest of the list
   [] L|R then {Filter R P}		%%recursion step
   end
end
fun {IsNonNegative X}
   if N>=0 then N
   end
end
{
 Browse
 {
  Filter IsNonNegative [1 ~1 3 ~7 5 2 ~3 ~5 6] 
 }
}
