# application_mantis

## User Manual

### Application Overview
This application simulates a material processing flow through different stations (A, B, C, D). Each station modifies the material, and the user can configure the flow between these stations.

### Steps to Use:
1. Set up the process flow by specifying the stations in the desired order (e.g., A->B->C).
2. Input a raw material (a number), which will be processed through the defined flow.
3. View the list of finished products.
4. View how many times each station has processed materials.
5. Exit the program.

### Process Logic:
- **Station A**: Adds 1 to the material.
- **Station B**: Subtracts 1 from the material.
- **Station C**: If the material is odd, sends it to the next station. If even, skips the next station.
- **Station D**: Mimics the previous station's behavior.

When the program exits, the finished products are saved and loaded automatically when you restart the program.
