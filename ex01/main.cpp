#include "Serializer.hpp"
int main()
{
	Data *m;
	m= new Data;
	m->content = "Raghda";
	m->next = NULL;
	uintptr_t q =Serializer::serialize(m);
	Data *n;
	n = Serializer::deserialize(q);
	std::cout << "n content is "<<n->content<<"\n";
}
