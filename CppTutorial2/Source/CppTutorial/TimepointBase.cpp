#include "TimepointBase.h"


UTimepointBase* UTimepointBase::Interpolate_Implementation(const UTimepointBase other, float distance) const
{
	return DuplicateObject(this,nullptr);
}
