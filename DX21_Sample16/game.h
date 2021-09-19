#pragma once

class Game {
public:
	void Initialize(void);
	void Terminate(void);
	void Update(void);
	void Draw(void);

	int result=1;
	int stage_num;

	const int stage_num_max = 3;
	//Player player;

	bool stage_num_flag;
};
