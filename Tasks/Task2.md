# ������������ ������ #2

��� ������ ��������� ��������:
- ������ � ������� � ������������
- ���������� IPC

## �������
�������� 2 ����������: ������ � ������.

������ ���������� � �������, ��������� ���� � ��������� �����. � ����� ������ ���������� ������ ���� ����� (������ ���� ������ � �����)

��� ��������� ������ ���� ������������ � 2-� �������: ��� Linux � ��� Windows.
������ ��� Windows ���������� Named Pipes, ������ ��� Linux - FIFO.

 
��������� ������� �������:
```
<your program> -� <channel_name>
```
���:
- -� \<channel_name\> - ��� Named Pipe ��� FIFO, ������� ������� ������ ��� ����������� ��������

��������� ������� �������:
```
<your program> -� <channel_name> -d <directory_path> [-r]
```
���:
- -� \<channel_name\> - ��� Named Pipe ��� FIFO ����� ���������� ��������.
- -d <directory_path> - ������ ���� � ����������, ������ ������� ��������� ����������
- -r - ������� ������ ����������. ���� ���� ���� �� ������, �� �������������� ������ ������ ������, ��������������� ������������� � ����������, � ���� ������ - �� � �� ���� �������������� 
