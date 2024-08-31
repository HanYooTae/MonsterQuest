## 프로젝트 소개

### Stage를 클리어하고 신규 무기를 받아 적을 처치하는 게임

- 개인 포트폴리오 / Unreal Engine 4.27

## 프로젝트 소개 영상

[![MosterQuest 겉표지](https://github.com/user-attachments/assets/44dea5cb-dffc-41d2-ba19-e30568c0f96d)
](https://www.youtube.com/watch?v=h9lBu16z-HU&t=12s)


## 개발 기간
- 2024/03/29 ~ 2024/08/21


## 프로젝트 목차


### 아이템

> + #### 아이템 개요
>   아이템의 장착은 DataAsset으로 관리하고 있으며, 해당 DataAsset은 아이템의 정보, 장착, 공격 등의 정보를 관리한다.
>   + [상세보기](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Item/%EC%95%84%EC%9D%B4%ED%85%9C%20%EA%B0%9C%EC%9A%94.md)
> + #### 아이템 구성
>   아이템은 4가지 종류로 나뉘어져 있으며, 아이템을 관리하는 DataAsset에서 관리한다.
>   + [상세보기](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Item/%EC%95%84%EC%9D%B4%ED%85%9C%20%EA%B5%AC%EC%84%B1.md)


### 인벤토리

> + #### 인벤토리 개요
>   인벤토리는 총 3개의 Widget으로 구성되어있으며, 파생 Widget이 추가로 존재한다.
>   + [상세보기](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Inventory/%EC%9D%B8%EB%B2%A4%ED%86%A0%EB%A6%AC%20%EA%B0%9C%EC%9A%94.md)
> +  #### 아이템 상호작용
>    아이템과의 상호작용을 통해서 인벤토리에 아이템을 넣을 수 있다.
>     + [상세보기](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Inventory/%EC%95%84%EC%9D%B4%ED%85%9C%20%EC%83%81%ED%98%B8%EC%9E%91%EC%9A%A9.md)
> + #### 인벤토리 동작 구조
>   아이템을 장착 또는 해제하여 월드상에 아이템을 Spawn or Destroy할 수 있다.
>   + [상세보기](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Inventory/%EC%9D%B8%EB%B2%A4%ED%86%A0%EB%A6%AC%20%EB%8F%99%EC%9E%91%20%EA%B5%AC%EC%A1%B0.md)


### 캐릭터

> + #### 사용자 컴포넌트
>   사용자 컴포넌트는 플레이어와 몬스터를 구분하지 않고 사용하는 컴포넌트와, 구분하는 단일 사용 컴포넌트가 존재한다.
>     + [상세보기](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/ActorComponents/%EC%82%AC%EC%9A%A9%EC%9E%90%20%EC%A0%95%EC%9D%98%20%EC%BB%B4%ED%8F%AC%EB%84%8C%ED%8A%B8.md)
>
> + 플레이어
>    + [플레이어 개요](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Player/%ED%94%8C%EB%A0%88%EC%9D%B4%EC%96%B4%20%EA%B0%9C%EC%9A%94.md)
>    + [플레이어 상호작용](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Player/%ED%94%8C%EB%A0%88%EC%9D%B4%EC%96%B4%20%EC%83%81%ED%98%B8%EC%9E%91%EC%9A%A9.md)
>
> + 몬스터
>    + [몬스터 개요](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Enemy/%EB%AA%AC%EC%8A%A4%ED%84%B0%20%EA%B0%9C%EC%9A%94.md)
>    + [몬스터 구성](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Enemy/%EB%AA%AC%EC%8A%A4%ED%84%B0%20%EA%B5%AC%EC%84%B1.md)

### 포탈

> + [포탈 구성](https://github.com/HanYooTae/MonsterQuest/blob/main/Outline/Portal/%ED%8F%AC%ED%83%88%20%EA%B5%AC%EC%84%B1.md)
