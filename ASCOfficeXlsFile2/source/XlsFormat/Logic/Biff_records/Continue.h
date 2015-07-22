#pragma once

#include "BiffRecord.h"

namespace XLS
{;


// Logical representation of Continue record in BIFF8
class Continue: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(Continue)
	BASE_OBJECT_DEFINE_CLASS_NAME(Continue)
public:
	Continue();
	~Continue();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeContinue;
};

} // namespace XLS

