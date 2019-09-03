int getroot(struct node root)
{
	if(parent[a]==a)
	return a;
	else return getroot(a);
}
int getroot(struct node root)
{
	if(parent[a]!=a)
	parent[a]=getroot(parent[a]);
	return parent[a];
}
