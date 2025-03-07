# BOOK_ID별 sales그룹화
with ONLY_2022 as
(
    select * from BOOK_SALES
    where year(SALES_DATE)=2022 and month(SALES_DATE) = 1
),
BOOK_SALED_GROUP as
(
select BOOK_ID,sum(SALES) as acc from ONLY_2022 
    group by BOOK_ID
),
AUTHOR_INTG as (
select BOOK_ID,CATEGORY,t1.AUTHOR_ID,PRICE,PUBLISHED_DATE,t2.AUTHOR_NAME
    from BOOK as t1 join AUTHOR as t2
        on t1.AUTHOR_ID = t2.AUTHOR_ID
),
FULL_T as (
select t1.book_id,CATEGORY,AUTHOR_ID,price,PUBLISHED_DATE,AUTHOR_NAME,acc
    from AUTHOR_INTG as t1 join BOOK_SALED_GROUP as t2
        on t1.BOOK_ID = t2.BOOK_ID
),
T3 as (
select BOOK_ID,AUTHOR_ID,AUTHOR_NAME,CATEGORY,
    acc*price as TOTAL_SALES
    from FULL_T
)

select AUTHOR_ID,AUTHOR_NAME,CATEGORY,
    sum(TOTAL_SALES) as TOTAL_SALES
from t3
group by AUTHOR_ID, AUTHOR_NAME,CATEGORY
order by AUTHOR_ID asc, category desc
# select * from BOOK_SALED_GROUP
# select * from BOOK_SALES where book_id = 1
# select * from FULL_T

# select AUTHOR_ID,AUTHOR_NAME,CATEGORY


# 