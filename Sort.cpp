void sort(int* a, int first, int last){
	int i = first, j = last;
	int tmp, pivot = a[(first + last) / 2];
	while(true) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j)
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
		if (i >= j)
			break;
	}
	if (i < last)
		sort(a, i, last);
	if (first < j)
		sort(a, first, j);
}
