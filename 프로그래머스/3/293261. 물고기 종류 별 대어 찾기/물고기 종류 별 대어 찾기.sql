# select aa.ID,aa.FISH_NAME,max(aa.LENGTH)




select ID,FISH_NAME,tm.LENGTH from FISH_INFO as f3
inner join 
(
    select aa.FISH_TYPE,aa.FISH_NAME, max(aa.LENGTH) as LENGTH
    from (select f1.ID,f1.FISH_TYPE,
            CASE WHEN LENGTH is null THEN 0
                ELSE LENGTH END as LENGTH
            ,TIME,f2.FISH_NAME from FISH_INFO as f1
        inner join FISH_NAME_INFO as f2 
            on f1.FISH_TYPE = f2.FISH_TYPE) as aa
    group by aa.FISH_TYPE, aa.FISH_NAME
    ) as tm
on f3.FISH_TYPE = tm.FISH_TYPE and f3.LENGTH = tm.LENGTH
order by ID asc
