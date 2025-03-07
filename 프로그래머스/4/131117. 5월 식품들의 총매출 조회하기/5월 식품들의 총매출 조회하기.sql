-- 코드를 입력하세요
-- PRODUCT_ID, sum(AMOUNT) 그룹화 -> 단, PRODUCE_DATE가 2022-05인 것만
-- T1 테이블로

-- 
-- 이때 결과는 총매출을 기준으로 내림차순 정렬해주시고 총매출이 같다면 식품 ID를 기준으로 오름차순 정렬해주세요.

with T_SUM as
(
SELECT PRODUCT_ID, sum(AMOUNT) as SUM_AMOUNT
from (select * from FOOD_ORDER where year(PRODUCE_DATE)=2022 and month(PRODUCE_DATE) = 5) as FO_FILTERED
group by PRODUCT_ID)

select t1.PRODUCT_ID, PRODUCT_NAME, SUM_AMOUNT*PRICE as TOTAL_SALES
from T_SUM as t1 join FOOD_PRODUCT as fp
    on t1.PRODUCT_ID = fp.PRODUCT_ID
order by TOTAL_SALES desc, t1.PRODUCT_ID asc

