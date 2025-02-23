select tj2.ID, tj2.FISH_NAME,tj2.LENGTH
from (select f11.ID, f11.fISH_TYPE, f22.FISH_NAME,f11.LENGTH
        from FISH_INFO as f11 inner join FISH_NAME_INFO as f22 on f11.FISH_TYPE
            = f22.FISH_TYPE) as tj2
where 
    (tj2.FISH_TYPE,tj2.FISH_NAME,tj2.LENGTH)
    in
    (select tj.FISH_TYPE,tj.FISH_NAME, max(LENGTH) as LENGTH
    from
        (select f1.ID, f1.fISH_TYPE, f2.FISH_NAME,f1.LENGTH
        from FISH_INFO as f1 inner join FISH_NAME_INFO as f2 on f1.FISH_TYPE
            = f2.FISH_TYPE) as tj
    group by tj.FISH_TYPE, tj.FISH_NAME)
order by tj2.ID asc



# select ID,FISH_NAME,tm.LENGTH from FISH_INFO as f3
# inner join 
# (
#     select aa.FISH_TYPE,aa.FISH_NAME, max(aa.LENGTH) as LENGTH
#     from (select f1.ID,f1.FISH_TYPE,
#             CASE WHEN LENGTH is null THEN 0
#                 ELSE LENGTH END as LENGTH
#             ,TIME,f2.FISH_NAME from FISH_INFO as f1
#         inner join FISH_NAME_INFO as f2 
#             on f1.FISH_TYPE = f2.FISH_TYPE) as aa
#     group by aa.FISH_TYPE, aa.FISH_NAME
#     ) as tm
# on f3.FISH_TYPE = tm.FISH_TYPE and f3.LENGTH = tm.LENGTH
# order by ID asc