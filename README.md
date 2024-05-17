<h2><현재 진행도></h2>

<h3>1. ActionComponent - DataAsset을 관리하는 컴포넌트</h3>

- DataAsset에 Weapon, Equipment Montage, DoAction이 존재
- DataAsset을 관리하는 ActionComponent에 4가지 무기를 관리하는 Enum인 EActionType이 존재(Unarmed, Sword, Pistol, Rifle, Sniper, Max)
- Sword는 이미 DataAsset으로 전부 만들어놓은 상태
- Pistol, Rifle, Sniper는 Weapon과 Equipment Montage까지 만들어놓은 상태 (DoAction은 만들었는데 만들고 보니 총쏠 때 굳이 몽타주를 넣지 않아도 되겠다고 생각하여 총기 전용 클래스를 만들어서 이관하는 중)


<h3>2. CWeapon_Guns - Pistol, Rifle, Sniper를 관리하는 클래스</h3>

- 위의 3가지 무기를 CWeapon_Guns의 자식으로 상속시킴
- Equipment Montage는 DataAsset에서 만들어놓은 것이 있어서 제외(변경해야하나 고민 중)
- Sound, CameraShake, 재장전 등은 시기상조, 총알 격발 먼저 만들고 있는 중
- 공격키는 무기와 상관없이 Ctrl키로 통일할 예정이지만, test를 위해서 일단 총 무기만 다른 키로 격발되도록 만드는 중
- PlayerSetupComponent에 ACWeapon_Guns의 Begin_Fire를 BindAction했지만, Actor를 상속받고 있는 클래스라서 에러가 뜸. 총 무기의 USceneComponent를 Player에 Has-A관계로 묶어준 후에 사용해도 될 것 같고 당장은 편할 수도 있으나, 종류가 3개이므로 총 무기를 관리하는 ActorComponent를 만든 후에 관리해주지 않으면 추후에 굉장히 불편해질 가능성이 너무 큼.
- 총 무기를 관리하는 GunComponent를 만든 후에 총 종류를 관리해주는 EGunType을 만들어 Unarmed, Pistol, Rifle, Sniper, Max를 만들어 관리 예정


<h4> 고찰 </h4>

- 무기를 관리하는 방법이 2가지(근접 무기는 DataAsset, 원거리 무기는 무기 자체에서 관리)가 되었는데, 만드는데 문제는 없겠지만 이게 과연 좋은 방법일까?
- 구상 중에, 좌측 하단에 Sword, Pistol, Rifle, Sniper 순서대로 무기의 초상화를 담은 Widget을 만들어서 들고 있는 무기의 초상화가 활성화되도록 만들 예정인데, EnumType이 2개가 된다면 만들 수 있는 방법이 있을까?(Widget에 초상화를 겹치게 만들어서 Sword를 선택하면 겹쳐진 부분이 활성화되도록(활성화되어도 안보이도록) 변경, 총 무기들도 마찬가지로 관리로 된다면 다행..)
