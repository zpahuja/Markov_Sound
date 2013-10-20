

struct markov_row
{
	int output_states;
	float * probabilities;
};

//uses ints to index all the states
struct markov_chart
{
	int input_states;
	int output_states;
	markov_row * rows;
};


markov_row get_markov_row(markov_chart * mc, int in_state)
{
	return mc->rows[in_state];
}

int evaluate_row(markov_row * mr)
{
	markov_row norm = normalized(mr);
	float random_sample = (rand() / (float)RAND_MAX);
	float probability_sum = 0.0;
	for(int i = 0; i < mr->output_states; i++)
	{
		probability_sum += norm[i];
		if(random_sample <= probability_sum)
		{
			return i;
		}
	}
}