import json
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('Qt5Agg')

with open('C:\\Qt\\Projects\\SDE\\build-EulerAndMCmethod-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\test1.json',
          'r') as file1:
    data1 = json.load(file1)

with open('C:\\Qt\\Projects\\SDE\\build-EulerAndMCmethod-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\test2.json',
          'r') as file2:
    data2 = json.load(file2)

# словарь для хранения траекторий по их trajectory_id
trajectories = {}

# группировка траекторий из первого файла
for traj in data1['trajectories']:
    traj_id = traj['trajectory_id']
    if traj_id not in trajectories:
        trajectories[traj_id] = {'A': [], 'B': []}
    trajectories[traj_id]['A'] = traj['data']

# группировка траекторий из второго файла
for traj in data2['trajectories']:
    traj_id = traj['trajectory_id']
    if traj_id not in trajectories:
        trajectories[traj_id] = {'A': [], 'B': []}
    trajectories[traj_id]['B'] = traj['data']

# графики для объединенных траекторий
for traj_id, data in trajectories.items():
    plt.figure()  # новое окно для каждой траектории
    plt.plot(data['A'], label=f'Prey', color='green')
    plt.plot(data['B'], label=f'Predator', color='orange')
    plt.title(f'The Lotka — Volterra model (Trajectory {traj_id})')
    plt.xlabel('Step')
    plt.ylabel('Population')
    plt.legend()

plt.show()  # отображение окон
