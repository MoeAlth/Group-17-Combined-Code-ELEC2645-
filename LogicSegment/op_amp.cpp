//ELEC/XJEL2645
// Dr Craig A. Evans and Dr Tim J. Amsdon

#include <iostream>


#include "easyx.h"
#include "cmath"
#include "stdio.h"
#include "graphics.h "
#include "windows.h"
#include "Window.h"//my own code for my window.
#include "Windowcompli.h"
#include "Size_parameter.h"
#include "Table.h"

/*
void back_ground() {
	IMAGE bk;
	loadimage(&bk, _T("image/bgk.png"), 960, 640);
	putimage(0, 0, &bk);
	getchar();
}
*/
void system_window()
{
	system("title op_amp");
	system("color f0");
	system("mode con cols=70 lines=20");
}//trial window.

int main0(){
	while (true) {
		system_window();
	}
	
	return 0; 
}

int main00() {

	


	//my own window
	Window w(1420, 820, EW_SHOWCONSOLE);
	w.setWindowTitle("op_amp");

	//back_ground();

	Windowcompli wi;
	wi.run();

	/*
	while (true)
	{
		//windows command
		//system_window();







		//CIRCLE TRIAL

		/*std::cout << "input the radius of the circle\n";
		float a;
		std::cin >> a;
		circle.set_radius(a);
		float area = circle.get_area();
		std::cout << "The circle has an area of " << area << " m^2.\n";

		std::cout << "input the diameter of the circle\n";
		float b;
		std::cin >> b;
		circle.set_diameter(b);
		float circumference = circle.get_circumference();

		std::cout << "the circle has an circumference of" << circumference << "m.\n";

		std::cout << "input the sidelength of the square\n";
		float c;
		std::cin >> c;
		square.set_sidelength(c);
		float sarea = square.get_sarea();
		std::cout << "the square has an area of " << sarea << " m^2.\n";

		float perimeter = square.get_perimeter();
		std::cout << "the square has an perimeter of " << perimeter << " m.\n";*/

	/*
	std::cout << "input the first resistor value of the non inverting amplifier:\n";
	float r1;
	std::cin >> r1;
	gain.set_resistor1(r1);


	std::cout << "input the second resistor value of the non inverting amplifier:\n";
	float r2;
	std::cin >> r2;
	gain.set_resistor2(r2);

	float _closeloopG = gain.get_closeloopG();
	float _fratio = gain.get_Fratio();

	std::cout << "the closed loop gain is: " << _closeloopG << ".\n\n";
	std::cout << "the feedback ratio is: " << _fratio << ".\n\n";

	int i;
	std::cin >> i;

	//pictures:

	if (i == 10) {
		initgraph(640, 280, SHOWCONSOLE);
		setbkcolor(TRANSPARENT);
		cleardevice();

		IMAGE nv;
		loadimage(&nv, _T("E:/PIC/pj/ni.png"), 640, 280);
		putimage(0, 0, &nv);
		
		getchar();

		int k;
		std::cin >> k;
		if (k == 11) {
			closegraph();
		}
	}
	else if (i == 11) {
		initgraph(640, 280, SHOWCONSOLE);
		setbkcolor(TRANSPARENT);
		cleardevice();

		IMAGE IV;
		loadimage(&IV, _T("E:/PIC/pj/iv.png"), 640, 280);
		putimage(0, 0, &IV);
		getchar();
	
		int k;
		std::cin >> k;
		if (k == 11) {
			closegraph();
		}
	}


}*/

	return w.exec();
}