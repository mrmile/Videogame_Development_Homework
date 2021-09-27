
#include <math.h>
#include <tgmath.h>
#include <windows.h>
#include <iostream>
using namespace std;

class Vec3
{
public:

	Vec3()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3(Vec3& AnotherVector)
	{
		this->x = AnotherVector.x;
		this->y = AnotherVector.y;
		this->z = AnotherVector.z;
	}

	Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) { }

	~Vec3() {}


	float x;
	float y;
	float z;

	Vec3 operator + (Vec3 AnotherVector)
	{
		Vec3 ResultVector;

		ResultVector.x = this->x + AnotherVector.x;
		ResultVector.y = this->y + AnotherVector.y;
		ResultVector.z = this->z + AnotherVector.z;

		return ResultVector;
	}

	Vec3 operator - (Vec3 AnotherVector)
	{
		Vec3 ResultVector;

		ResultVector.x = this->x - AnotherVector.x;
		ResultVector.y = this->y - AnotherVector.y;
		ResultVector.z = this->z - AnotherVector.z;

		return ResultVector;
	}

	Vec3 operator += (Vec3 AnotherVector)
	{
		Vec3 ResultVector;

		ResultVector.x = this->x + AnotherVector.x;
		ResultVector.y = this->y + AnotherVector.y;
		ResultVector.z = this->z + AnotherVector.z;

		this->x = ResultVector.x;
		this->y = ResultVector.y;
		this->z = ResultVector.z;

		return ResultVector;
	}

	Vec3 operator -= (Vec3 AnotherVector)
	{
		Vec3 ResultVector;

		ResultVector.x = this->x - AnotherVector.x;
		ResultVector.y = this->y - AnotherVector.y;
		ResultVector.z = this->z - AnotherVector.z;

		this->x = ResultVector.x;
		this->y = ResultVector.y;
		this->z = ResultVector.z;

		return ResultVector;
	}

	Vec3 operator = (Vec3 AnotherVector)
	{
		Vec3 ResultVector;

		ResultVector.x = AnotherVector.x;
		ResultVector.y = AnotherVector.y;
		ResultVector.z = AnotherVector.z;

		this->x = ResultVector.x;
		this->y = ResultVector.y;
		this->z = ResultVector.z;

		return ResultVector;
	}

	bool operator == (Vec3 AnotherVector)
	{
		int ConditionsOk = 0;


		float Vector01Module;
		float Vector02Module;

		Vector01Module = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		Vector02Module = sqrt(AnotherVector.x * AnotherVector.x + AnotherVector.y * AnotherVector.y + AnotherVector.z * AnotherVector.z);

		if (Vector01Module == Vector02Module) ConditionsOk++;


		double AngleBetweenVectors;

		AngleBetweenVectors = (this->x * AnotherVector.x + this->y * AnotherVector.y + this->z * AnotherVector.z) / 
			(sqrt(this->x * this->x + this->y * this->y + this->z * this->z) * sqrt(AnotherVector.x * AnotherVector.x + AnotherVector.y * AnotherVector.y + AnotherVector.z * AnotherVector.z));

		AngleBetweenVectors = acos(AngleBetweenVectors);

		if(AngleBetweenVectors == 0) ConditionsOk++;


		if (ConditionsOk == 2) return true;
		else return false;
	}

	void Normalize()
	{
		float VectorModule;
		VectorModule = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);

		this->x = this->x / VectorModule;
		this->y = this->y / VectorModule;
		this->z = this->z / VectorModule;
	}

	void Zero()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	bool IsZero()
	{
		if (this->x == 0 && this->y == 0 && this->z == 0) return true;
		else return false;
	}

	float DistanceTo(Vec3 AnotherPoint) // (x,y,z) Are points not vectors in this case
	{
		float Result;

		Result = sqrt(pow(this->x - AnotherPoint.x, 2) + pow(this->y - AnotherPoint.y, 2) + pow(this->z - AnotherPoint.z, 2));

		return Result;
	}
};

int main()
{
	//cout << "\n\n\n\n                      /HOMEWORK01: VEC3 CLASS PRACTICE/\n\n\n\n";
	//cout << "Only compatible with Windows OS\n\n";
	//system("pause");
	//system("cls");

	cout << "Create Vectors:";

	cout << "\n\n";

	Vec3 Vector1(0, 0, 0);
	Vec3 Vector2(0, 0, 0);

	cout << "Introduce vector #1 first component:";
	cin >> Vector1.x;
	cout << "Introduce vector #1 second component:";
	cin >> Vector1.y;
	cout << "Introduce vector #1 third component:";
	cin >> Vector1.z;

	cout << "\n";


	cout << "Introduce vector #2 first component:";
	cin >> Vector2.x;
	cout << "Introduce vector #2 second component:";
	cin >> Vector2.y;
	cout << "Introduce vector #2 third component:";
	cin >> Vector2.z;

	cout << "\n\n";
	cout << "--Vectors Created--";

	Sleep(1000);

	bool exit = false;
	int selection;

	while (exit == false) // Faltan por hacer: 7, 8, 9
	{
		system("cls");

		cout << "\n";
		cout << "Vectors:\n\n";

		cout << "Vector #1: (" << Vector1.x << "," << Vector1.y << "," << Vector1.z << ")\n";
		cout << "Vector #2: (" << Vector2.x << "," << Vector2.y << "," << Vector2.z << ")\n";

		cout << "\n\n";

		selection = 0;

		cout << "[1] V1 + V2\n[2] V1 - V2\n[3] V1 += V2\n[4] V1 -= V2\n[5] Reintroduce Vectors\n[6] Compare vectors\n[7] Normalize vector\n[8] Convert to vector zero\n[9] Distance between two points(uses values x,y,z from vectors)\n[10] Check if its a vector zero\n[11] Exit\n";

		cout << "Select an option:";
		cin >> selection;

		if (selection == 1) //[1] V1 + V2
		{
			system("cls");

			Vec3 Result;

			cout << "V1 + V2\n\n";
			cout << "Result:\n\n";

			Result = Vector1 + Vector2;
			//Result = Vector1.operator+(Vector2);
			cout << "V1 + V2 = (" << Result.x << "," << Result.y << "," << Result.z << ")\n";

			cout << "\n";
			system("pause");
		}
		else if (selection == 2) //[2] V1 - V2
		{
			system("cls");

			Vec3 Result;

			cout << "V1 - V2\n\n";
			cout << "Result:\n\n";

			Result = Vector1 - Vector2;
			cout << "V1 + V2 = (" << Result.x << "," << Result.y << "," << Result.z << ")\n";

			cout << "\n";
			system("pause");
		}
		else if (selection == 3) //[3] V1 += V2
		{
			system("cls");


			cout << "V1 += V2\n\n";
			cout << "Result:\n\n";

			Vector1 += Vector2;
			cout << "V1 += V2 = (" << Vector1.x << "," << Vector1.y << "," << Vector1.z << ")\n";

			cout << "\n";
			system("pause");
		}
		else if (selection == 4)  //[4] V1 -= V2
		{
			system("cls");


			cout << "V1 -= V2\n\n";
			cout << "Result:\n\n";

			Vector1 -= Vector2;
			cout << "V1 -= V2 = (" << Vector1.x << "," << Vector1.y << "," << Vector1.z << ")\n";

			cout << "\n";
			system("pause");
		}
		else if (selection == 5) //[5] Reintroduce Vectors
		{
			bool submenuExit = false;

			while (submenuExit == false)
			{
				system("cls");
				int subselection = 0;
				cout << "Reintroduce Vectors\n\n";

				cout << "[1] V1\n[2] V2\n";

				cout << "Select Vector:";
				cin >> subselection;

				if (subselection == 1)
				{
					Vec3 NewVector(0, 0, 0);
					cout << "\n";

					cout << "Introduce vector #1 first component:";
					cin >> NewVector.x;
					cout << "Introduce vector #1 second component:";
					cin >> NewVector.y;
					cout << "Introduce vector #1 third component:";
					cin >> NewVector.z;

					Vector1 = NewVector;

					submenuExit = true;

					cout << "\n\n";
					system("pause");
				}
				else if (subselection == 2)
				{
					Vec3 NewVector(0, 0, 0);

					cout << "Introduce vector #2 first component:";
					cin >> NewVector.x;
					cout << "Introduce vector #2 second component:";
					cin >> NewVector.y;
					cout << "Introduce vector #2 third component:";
					cin >> NewVector.z;

					Vector2 = NewVector;

					submenuExit = true;

					cout << "\n\n";
					system("pause");
				}
				else
				{
					system("cls");

					cout << "\nPlease select a valid option\n";
					system("pause");
				}
			}
		}
		else if (selection == 6) //[6] Compare vectors
		{
			system("cls");
			cout << "Compare Vectors \n\n";

			bool Result;

			Result = Vector1 == Vector2;

			if (Result == true) cout << "Vectors are equal";
			else cout << "Vectors are not equal";

			Sleep(500);
			cout << "\n\nNot sure if actually it worked properly...";

			cout << "\n\n";
			system("pause");
		}
		else if (selection == 7) //[7] Normalize vector
		{
			bool submenuExit = false;

			while (submenuExit == false)
			{
				system("cls");
				cout << "Normalize vector\n\n";

				int subselection = 0;

				cout << "[1] V1\n[2] V2\n";

				cout << "Select Vector:";
				cin >> subselection;

				if (subselection == 1)
				{
					Vector1.Normalize();
					cout << "\n";

					cout << "Normalized vector #1: (" << Vector1.x << "," << Vector1.y << "," << Vector1.z << ")\n";

					submenuExit = true;

					cout << "\n";
					system("pause");
				}
				else if (subselection == 2)
				{
					Vector2.Normalize();
					cout << "\n";

					cout << "Normalized vector #2: (" << Vector2.x << "," << Vector2.y << "," << Vector2.z << ")\n";

					submenuExit = true;

					cout << "\n";
					system("pause");
				}
				else
				{
					system("cls");

					cout << "\nPlease select a valid option\n";
					system("pause");
				}
			}
		}
		else if (selection == 8) //[8] Convert to vector zero
		{
		bool submenuExit = false;

		while (submenuExit == false)
		{
			system("cls");
			int subselection = 0;

			cout << "[1] V1\n[2] V2\n";

			cout << "Select Vector:\n";
			cin >> subselection;

			if (subselection == 1)
			{
				Vector1.Zero();
				cout << "\n";

				cout << "Vector #1: (" << Vector1.x << "," << Vector1.y << "," << Vector1.z << ")\n";

				submenuExit = true;

				cout << "\n";
				system("pause");
			}
			else if (subselection == 2)
			{
				Vector2.Zero();
				cout << "\n";

				cout << "Vector #2: (" << Vector2.x << "," << Vector2.y << "," << Vector2.z << ")\n";

				submenuExit = true;

				cout << "\n";
				system("pause");
			}
			else
			{
				system("cls");

				cout << "\nPlease select a valid option\n";
				system("pause");
			}
		}
		}
		else if (selection == 9) //[9] Distance between two points(uses values x,y,z from vectors)
		{
			system("cls");

			float result;

			result = Vector1.DistanceTo(Vector2);

			cout << "Distance between:(" << Vector1.x << "," << Vector1.y << "," << Vector1.z << ") and (" << Vector1.x << "," << Vector1.y << "," << Vector1.z << ") is = " << result;

			cout << "\n";
			system("pause");
		}
		else if (selection == 10) //[10] Check if its a vector zero
		{
		bool submenuExit = false;

		while (submenuExit == false)
		{
			system("cls");
			cout << "Normalize vector:\n\n";

			int subselection = 0;

			cout << "[1] V1\n[2] V2\n";

			cout << "Select Vector:\n";
			cin >> subselection;

			if (subselection == 1)
			{
				bool result;
				result = Vector1.IsZero();
				cout << "\n";

				if(result == true) cout << "Vector #1 is a vector zero\n";
				else cout << "Vector #1 is not a vector zero\n";

				submenuExit = true;

				cout << "\n";
				system("pause");
			}
			else if (subselection == 2)
			{
				bool result;
				result = Vector2.IsZero();
				cout << "\n";

				if (result == true) cout << "Vector #2 is a vector zero\n";
				else cout << "Vector #2 is not a vector zero\n";

				submenuExit = true;

				cout << "\n";
				system("pause");
			}
			else
			{
				system("cls");

				cout << "\nPlease select a valid option\n";
				system("pause");
			}
		}
		}
		else if (selection == 11) //[10] Exit
		{
			system("cls");

			exit = true;
			cout << "Exiting...";
			Sleep(500);
			cout << "\n\n\n";

		}
		else if (selection == 14) //[14] ?????
		{
			system("cls");

			cout << "\n\n";

			char A = 219;

			cout << "      " << A << A << A << A << " " << "\n";
			cout << "      " << A << " " << " " << A << " " << "\n";
			cout << "      " << A << A << A << A << A << "\n";
			cout << "      " << A << A << A << A << A << "\n";
			cout << "      " << A << A << A << A << A << "\n";
			cout << "      " << " " << A << " " << A << " " << "\n";
			cout << "      " << " " << A << " " << A << " " << "\n";

			cout << "\n\n";
			system("pause");
		}
		else
		{
			system("cls");

			cout << "\nPlease select a valid option\n\n";
			system("pause");
		}
	}

	cout << "\n\n";

	return 0;
}