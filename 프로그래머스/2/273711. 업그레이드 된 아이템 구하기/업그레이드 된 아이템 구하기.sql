with T1 as(
select a.ITEM_ID, ITEM_NAME, RARITY, PRICE, b.PARENT_ITEM_ID
from ITEM_INFO as a join ITEM_TREE as b on a.ITEM_ID = b.ITEM_ID
),
T2 as (select * from T1 where PARENT_ITEM_ID is not null),
T3 as (
select a.ITEM_ID, a.ITEM_NAME,a.RARITY,a.PRICE, b.ITEM_NAME as PARENT_ITEM_NAME, b.RARITY as PARENT_ITEM_RARITY
    from T2 as a join ITEM_INFO as b
        on a.PARENT_ITEM_ID = b.ITEM_ID
),
T4 as (
    select * from T3 where PARENT_ITEM_RARITY = "RARE"
)
select ITEM_ID, ITEM_NAME, RARITY from T4 order by ITEM_ID desc
# select ITEM_ID, ITEM_NAME, RARITY from T3 order by ITEM_ID desc








# 첫 풀이
#
# # 1. RARE인 아이템만 ITEM_INFO 추출
# #   -> ITEM_INFO_RARE
# with ITEM_INFO_RARE as (
# select * from ITEM_INFO where RARITY = "RARE"
# ),
# # 2. 이제 이 레어 아이템의 다음 강화 템들을 추출
# #   => ITEM_TREE에서 parent_item_id가 ITEM_INFO_RARE.ITEM_ID에 들어 있는 대상의 
# #   ITEM_ID 추출 ->  t3_tuple
# t3_tuple as (
# select ITEM_ID
#     from ITEM_TREE 
#     where ITEM_TREE.PARENT_ITEM_ID in (select ITEM_ID from ITEM_INFO_RARE)
# )


# # 3. 다시 맨처음 ITEM_INFO 에서 "ITEM_ID in t3_tuple"을
# # 만족하는 것들 뽑아서 정렬후 리턴
# select ITEM_ID,ITEM_NAME,RARITY
# from ITEM_INFO
# where ITEM_ID in (select * from t3_tuple)
# order by ITEM_ID desc