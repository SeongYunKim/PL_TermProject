mainprog main;

int[2] global1, global2;
int global3;
float[100] global4;
float global5;
int global1;

function foo(arg1: int; arg2: float): float;
	int local1, local2;
	float arg2;
	int global1, local1;
	begin
		global1[0] = 1;
		global2[1] = 2;
		global3 = 0.3;
		global4 = 4.4;
		global5 = 5;
		global6 = 6;
		arg1 = 1;
		arg2 = 2.0;
		arg3 = 3;
		local1 = 1;
		local2 = 2;
		local3 = 3;
		local4 = 4;
		pro1(1);
		pro4(3);
		return global3
	end

procedure pro1(arg3: int);
    int local3;
    begin
        arg1 = 1;
        arg3 = 3;
        local1 = 1;
        local3 = 3
     end

procedure pro2(arg1: int; arg1: int; arg2: float);
    int local1;
    begin
        local1 = arg1 + arg2
    end

procedure pro2(arg1: int);
    begin
	print(arg1)
    end

begin
	global1 = 1;
	global7 = 7;
	arg1 = 1;
	local1 = 1;
	foo(3, global5);
	foo(3, global7);
	pro1(2);
	pro3(4)
end


