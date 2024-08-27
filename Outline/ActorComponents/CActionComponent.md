## CActionComponent

#### 캐릭터가 장착한 무기를 관리하는 컴포넌트

```
UENUM(BlueprintType)
enum class EActionType : uint8
{
	Unarmed, Sword, Pistol, Rifle, Sniper, Max
};
```

- Unarmed : 어떤 무기도 장착하지 않은 상태
- Sword : 캐릭터가 검을 사용할 수 있는 상태, 콤보 공격이 가능하다.
- Pistol : 캐릭터가 권총을 사용할 수 있는 상태, 반동이 심하며 연사 속도가 느리다.
- Rifle : 캐릭터가 라이플을 사용할 수 있는 상태, 반동이 조금 있으며 연사 속도가 빠르다.
- Sniper : 캐릭터가 저격총을 사용할 수 있는 상태, 반동이 거의 없으며 연사 속도가 매우 느리다.

------------------------

#### 무기는 DataAsset으로 만들었으며 플레이어와 적, 모두 데이터 에셋을 사용
  ![image](https://github.com/user-attachments/assets/6a6fd0fe-8a07-4232-8b6d-170f0ddf6f10)
