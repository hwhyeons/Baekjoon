-- 
-- 1. CAR_RENTAL_COMPANY_CAR 에서 '통풍시트', '열선시트', '가죽시트'가 있는 테이블만
-- 따로 select해서 
-- -> T1
-- 
-- 2. T1에서 CAR_TYPE을 기준으로 group by
--      select CAR_TYPE, count(*) as CARS from T1 group by CAR_TYPE
-- 

with T1 as (
    select * from CAR_RENTAL_COMPANY_CAR
    where options like '%통풍시트%' or options like '%열선시트%'
        or options like '%가죽시트%'
)

select CAR_TYPE, count(*) as CARS from T1 group by CAR_TYPE
order by CAR_TYPE asc
