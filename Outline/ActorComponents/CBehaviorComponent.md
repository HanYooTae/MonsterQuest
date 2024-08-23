## CBehaviorComponent

#### Enemy의 상태를 관리하는 컴포넌트
- Blackboard에서 생성해둔 key를 AIController로 전달하여 Enemy가 소유하고 있는 BehaviorTree를 동작시킨다.

```
UENUM(BlueprintType)
enum class EBehaviorType : uint8
{
	Wait, Approach, Action, Patrol, Hitted, Max
};
```

#### BehaviorTree
![image](https://github.com/user-attachments/assets/53eb552a-45ad-45ba-b086-3a090cdb62d3)
