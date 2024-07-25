#include "CEnemy/BehaviorTree/CBTTaskNode_Action.h"

#include "CEnemy/CEnemy.h"
#include "ActorComponents/CActionComponent.h"
#include "ActorComponents/CStateComponent.h"

#include "AIController.h"

#include "Global.h"

UCBTTaskNode_Action::UCBTTaskNode_Action()
{
	bNotifyTick = true;

	NodeName = "Action";
}

EBTNodeResult::Type UCBTTaskNode_Action::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

    AAIController* controller = OwnerComp.GetAIOwner();
    CheckNullResult(controller, EBTNodeResult::Failed);

    ACEnemy* enemy = Cast<ACEnemy>(controller->GetPawn());
    CheckNullResult(enemy, EBTNodeResult::Failed);

    UCActionComponent* actionComp = CHelpers::GetComponent<UCActionComponent>(enemy);
    CheckNullResult(actionComp, EBTNodeResult::Failed);

    RunningTime = 0.f;
    actionComp->DoAction();

    return EBTNodeResult::InProgress;
}

void UCBTTaskNode_Action::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

    AAIController* controller = OwnerComp.GetAIOwner();
    CheckNull(controller);

    ACEnemy* enemy = Cast<ACEnemy>(controller->GetPawn());
    CheckNull(enemy);

    UCStateComponent* stateComp = CHelpers::GetComponent<UCStateComponent>(enemy);
    CheckNull(stateComp);

    RunningTime += DeltaSeconds;

    if (RunningTime >= Delay)
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
