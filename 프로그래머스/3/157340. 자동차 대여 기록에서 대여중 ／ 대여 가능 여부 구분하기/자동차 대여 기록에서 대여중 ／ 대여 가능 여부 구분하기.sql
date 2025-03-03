-- 1. 하나라도 22.10.16에 해당하는 CAR_ID 테이블 받기
--      -> ALREADY_LIST
-- 2. CAR_ID를 group by로 묶고 해당 테이블 GT
--      -> GT


with ALREADY_LIST as
(
SELECT CAR_ID from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE <= '2022-10-16' and END_DATE >= '2022-10-16'
),
GT as (
select CAR_ID from CAR_RENTAL_COMPANY_RENTAL_HISTORY group by CAR_ID
)
-- 3. GT에서 ALREADY_LIST에 있으면 '대여중' 없으면 '대여 가능' AVAILABILITY 컬럼추가
--      -> GT2
-- 4. select CAR_ID, AVAILABILITY from GT2 order by CAR_ID desc
-- 
select CAR_ID, (case when CAR_ID in (select * from ALREADY_LIST) then '대여중'
    else '대여 가능' end) as AVAILABILITY
from GT
order by CAR_ID desc
