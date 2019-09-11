void Tarjan(u)
{
	dnf[u] = low[u] = ++nTimes; 
	stack.push(u);
	for(int i = 0 ; i < G[u].length; i  ++ )
	{
		if(!visited[i])
			{
				tarjan(i);
				low[u] = min(low[u],low[i]);
			}
		else if(visited[i])
		{
			low[u] = min(low[u],dnf[v]);
		}
	}
	if(dnf[u] == low[u])
	{
		while(u != v)
		{
			v = stack.pop
			cout<<v;
		}
	}
	cout<<endl;
}
