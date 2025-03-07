# 1. group by로 DIFFERENTIATION_DATE 별로 max(SIZE_OF_COLONY) 출력
# select YEAR, max(SIZE_OF_COLONY) as MAX_SIZE ~~
# 예시테이블
# YEAR | MAX_SIZE
# 2019 | 10
# 2020 | 100
# ...
# -> 해당 테이블 이름은 YEAR2MAXSIZE
with YEAR2MAXSIZE as
(
select year(DIFFERENTIATION_DATE) as YEAR, max(SIZE_OF_COLONY) as MAX_SIZE
    from ECOLI_DATA
    group by year(DIFFERENTIATION_DATE)
),
E2 as (
select ID,PARENT_ID,SIZE_OF_COLONY,year(DIFFERENTIATION_DATE) as YEAR, GENOTYPE
    from ECOLI_DATA 
)

# 2. select YEAR(서브스트링이용), 편차, ID
#  from ECOLI_DATA join YEAR2MAXSIZE 
#   on ECOLI_DATA.YEAR = YEAR2MAXSIZE.YEAR    
#  정렬:  YEAR asc, SIZE_OF_COLONY

select e.YEAR, y.MAX_SIZE-e.SIZE_OF_COLONY as YEAR_DEV, ID
from E2 as e join YEAR2MAXSIZE as y on e.YEAR = y.YEAR
order by e.YEAR asc, YEAR_DEV asc

# select * from ECOLI_DATA