#encoding "utf-8"
#include <date.cxx>
#GRAMMAR_ROOT S

/*
Animal -> Noun<kwtype=animal>;
WithWho -> 'у' (Adj<gnc-agr[1]>) Animal<gram='род', rt, gnc-agr[1]> interp (Sparrow.Who);
WithWho -> 'с' (Adj<gnc-agr[1]>) Animal<gram='твор', rt, gnc-agr[1]> interp (Sparrow.Who);
S -> Date interp (Sparrow.When) WithWho;
S -> WithWho Date interp (Sparrow.When);
  */

//DayOfWeek -> Noun<kwtype="день_недели">;      // используем слова из статьи "день_недели"
//Часы работы выставки: ежедневно с 10:00 до 18:00 (в четверг - с 13:00 до 21:00), кроме вторника. 
Time -> AnyWord<wff=/[0-9]{2}:[0-9]{2}/>; 
WorkHours -> "с" Time interp (WorkHours.Start) (AnyWord) Time interp (WorkHours.End);
WorkHours -> "в" DayOfWeek interp (WorkHours.Day) "-" WorkHours;
WorkHours -> "с" Time interp (WorkHours.Start);
WorkHours -> "до" Time interp (WorkHours.End);
S-> WorkHours;