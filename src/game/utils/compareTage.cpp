#include<string>
#include<game/utils/CompareTag.h>

bool CompareTag(
	std::string tag_a,
	std::string tag_b,
	std::string target_a,
	std::string target_b
) {
	if (tag_a == target_a && tag_b == target_b) return true;
	if (tag_b == target_a && tag_a == target_b) return true;

	return false;
}