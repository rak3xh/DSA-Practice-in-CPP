// C++ 20 Solution
//  #include <bits/stdc++.h>
//  using namespace std;
//  class Solution
//  {
//  public:
//      int countCoveredBuildings(int n, vector<vector<int>> &buildings)
//      {
//          // Map to store all y-coordinates for each x-coordinate
//          unordered_map<int, vector<int>> buildingsAtX;
//          // Map to store all x-coordinates for each y-coordinate
//          unordered_map<int, vector<int>> buildingsAtY;

//         // Group buildings by their x and y coordinates
//         for (const auto &building : buildings)
//         {
//             int xCoord = building[0];
//             int yCoord = building[1];
//             buildingsAtX[xCoord].push_back(yCoord);
//             buildingsAtY[yCoord].push_back(xCoord);
//         }

//         // Sort all y-coordinates for each x-coordinate group
//         for (auto &[x, yCoords] : buildingsAtX)
//         {
//             sort(yCoords.begin(), yCoords.end());
//         }

//         // Sort all x-coordinates for each y-coordinate group
//         for (auto &[y, xCoords] : buildingsAtY)
//         {
//             sort(xCoords.begin(), xCoords.end());
//         }

//         int coveredBuildingCount = 0;

//         // Check each building to see if it's covered
//         for (const auto &building : buildings)
//         {
//             int xCoord = building[0];
//             int yCoord = building[1];

//             // Get all buildings with same x-coordinate (vertical line)
//             const vector<int> &yCoordinatesAtSameX = buildingsAtX[xCoord];
//             // Get all buildings with same y-coordinate (horizontal line)
//             const vector<int> &xCoordinatesAtSameY = buildingsAtY[yCoord];

//             // Check if building is covered:
//             // - There exists a building to the left and right (on same y-coordinate)
//             // - There exists a building above and below (on same x-coordinate)
//             bool hasLeftBuilding = xCoordinatesAtSameY[0] < xCoord;
//             bool hasRightBuilding = xCoord < xCoordinatesAtSameY.back();
//             bool hasBottomBuilding = yCoordinatesAtSameX[0] < yCoord;
//             bool hasTopBuilding = yCoord < yCoordinatesAtSameX.back();

//             if (hasLeftBuilding && hasRightBuilding && hasBottomBuilding && hasTopBuilding)
//             {
//                 coveredBuildingCount++;
//             }
//         }

//         return coveredBuildingCount;
//     }
// };