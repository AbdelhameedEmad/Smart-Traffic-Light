//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package internship;
//
// TODO documentation
//
network Network
{
    parameters:
        int id = 0;
        @display("bgb=728,361;bgl=2");
    submodules:
        cloud: Cloud {
            @display("p=370,55");
        }
        fog: Fog {
            @display("p=281,138");

        }

        fog1: Fog {
            @display("p=410,138");
        }

        tl[8]: TL {


        }

    connections:


}

