#pragma once
#include <iostream>
#include <queue>
#include <iomanip>
#include "clsDate.h"

using namespace std;

class clsQueueLine
{

private:

	class Ticket {

	private:
		short _MenuWidth = 45;
		short _DelimiterLength = 25;

	
		short _TicketID;
		short _WaitingClients;
		short _WaitingTime;
		string _CurrentTime;
		string _Prefix;
		string _FullNumber;

	public:

		

		Ticket(string Prefix, short TicketID, short WaitingClients, short WaitingTime) {

			_Prefix = Prefix;
			_TicketID = TicketID;
			_WaitingClients = WaitingClients;
			_WaitingTime = WaitingTime;
			_CurrentTime = clsDate::GetCurrentTime();
		}

		string FullNumber() {
			return _Prefix + to_string(_TicketID);
		}

		void Print() {


			cout << setw(_MenuWidth) << left << "" << string(_DelimiterLength, '_') << endl << endl;

			cout << setw(_MenuWidth + 10) << left << "" << FullNumber() << endl << endl;

			cout << setw(_MenuWidth + 2) << left << "" << _CurrentTime << endl;
			cout << setw(_MenuWidth + 2) << left << "" << "Waiting Clients = " << _WaitingClients << endl;
			cout << setw(_MenuWidth + 3) << left << "" << "Serve Time in\n";
			cout << setw(_MenuWidth + 5) << left << "" << _WaitingTime << " Minutes." << endl;
			cout << setw(_MenuWidth) << left << "" << string(_DelimiterLength, '_') << endl << endl;

		}
	};


	string _QueuePrefix;
	short _WaitingTime;
	short _TotalTickets;
	queue <Ticket> _qTickets;

	short _TicketID;


	short _DelimiterLength;
	short _MenuWidth;


	queue <Ticket> _GetReverseCopy() {
		queue <Ticket> TempQueue = _qTickets;
		queue <Ticket> TempReversedQueue;
		short Counter = 1;
		queue <Ticket> TempPOPQueue;

		while (Counter <= TempQueue.size()) {
			TempPOPQueue = TempQueue;
			int qSize = TempPOPQueue.size() - Counter;

			for (int i = 0; i < qSize; i++) {
				TempPOPQueue.pop();
			}

			TempReversedQueue.push(TempPOPQueue.front());

			Counter++;
		}
		return TempReversedQueue;
	}




public:

	clsQueueLine(string QueuePrefix, short WaitingTime) {

		_QueuePrefix = QueuePrefix;
		_WaitingTime = WaitingTime;
		_TotalTickets = 0;

		_TicketID = 0;


		_DelimiterLength = 25;
		_MenuWidth = 45;
	}


	void IssueTicket() {

		

		_TicketID++;

		_TotalTickets++;

		Ticket MyTicket(_QueuePrefix, _TicketID, GetTotalWaitingClients(), GetTotalWaitingTime());
		
		_qTickets.push(MyTicket);
		


	}


	void PrintInfo() {

		cout << setw(_MenuWidth) << left << "" << string(_DelimiterLength, '_') << endl << endl;

		cout << setw(_MenuWidth + 7) << left << "" << "Queue Info" << endl;

		cout << setw(_MenuWidth) << left << "" << string(_DelimiterLength, '_') << endl << endl;

		cout << setw(_MenuWidth) << left << "" << "  Prefix          = " << _QueuePrefix << endl;
												    
		cout << setw(_MenuWidth) << left << "" << "  Total Tickets   = " << _TotalTickets << endl;
												    
		cout << setw(_MenuWidth) << left << "" << "  Served Clients  = " << GetServedClientsNumber() << endl;
												    
		cout << setw(_MenuWidth) << left << "" << "  Waiting Clients = " << GetTotalWaitingClients() << endl;

		cout << setw(_MenuWidth) << left << "" << string(_DelimiterLength, '_') << endl << endl;
	}

	void PrintTicketsLineLTR() {

		queue <Ticket> TempqTickets = _GetReverseCopy();
		Ticket MyTicket = TempqTickets.front();
		cout << setw(30) << "" << "Tickets:  ";

		while (!TempqTickets.empty()) {

			cout << MyTicket.FullNumber() << " --> ";
			TempqTickets.pop();
			if (!TempqTickets.empty()) MyTicket = TempqTickets.front();
		}
		cout << "\n\n";
	}

	void PrintTicketsLineRTL() {
		queue <Ticket> TempqTickets = _qTickets;
		Ticket MyTicket = TempqTickets.front();
		cout << setw(30) << "" << "Tickets:  ";

		while (!TempqTickets.empty()) {

			cout << MyTicket.FullNumber() << " <-- ";
			TempqTickets.pop();
			if (!TempqTickets.empty()) MyTicket = TempqTickets.front();
		}
		cout << "\n\n";
	}

	void PrintAllTickets() {

		queue <Ticket> TempqTickets = _qTickets;

		if (!TempqTickets.empty()) {



			cout << setw(_MenuWidth + 5) << left << "" << "---Tickets---" << endl;
			while (!TempqTickets.empty()) {

				TempqTickets.front().Print();

				TempqTickets.pop();
				
			}
		}
	}

	void ServeNextClient() {

		if (_qTickets.empty()) return;

		_qTickets.pop();
	}

	short GetTotalWaitingClients() {
		return _qTickets.size();
	}

	int GetTotalWaitingTime() {
		return _WaitingTime * GetTotalWaitingClients();
	}


	string WhoIsNext() {
		return _qTickets.empty()? "No Clients Left." : _qTickets.front().FullNumber();
	}

	int GetServedClientsNumber() {
		return _TotalTickets - GetTotalWaitingClients();
	}

};

