import json
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('Qt5Agg')

with open('C:\\Qt\\Projects\\SDE\\build-EulerAndMCmethod-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\test3.json',
          'r') as file1:
    data1 = json.load(file1)

with open('C:\\Qt\\Projects\\SDE\\build-EulerAndMCmethod-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\test4.json',
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
    # значения, которые меньше -150 или больше 150
    data['A'] = [val if -150 <= val <= 150 else None for val in data['A']]
    data['B'] = [val if -150 <= val <= 150 else None for val in data['B']]

    plt.figure()  # новое окно для каждой траектории
    plt.plot(data['A'], label=f'Prey', color='green')
    plt.plot(data['B'], label=f'Predator', color='orange')
    plt.title(f'The Lotka — Volterra model (Trajectory {traj_id})')
    plt.xlabel('Step')
    plt.ylabel('Population')
    plt.legend()
    # верхняя и нижняя граница y
    y_min = min(val for val in data['A'] + data['B'] if val is not None)
    y_max = max(val for val in data['A'] + data['B'] if val is not None)
    plt.ylim(y_min, y_max)

plt.show()  # отображение окон
