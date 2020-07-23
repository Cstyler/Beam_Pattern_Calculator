import diagram_calculator
import numpy as np

def main():
    start_azimuth, end_azimuth = -60, 60
    start_elevation, end_elevation = -50, 50
    n_azimuths, n_elevations = 100, 100
    main_petal, side_petal = 1, 2
    petal_width_azimuth, petal_width_elevation = 3, 4
    dc = diagram_calculator.DiagramCalculator(start_azimuth, end_azimuth,
    start_elevation, end_elevation,
    n_azimuths, n_elevations,
    main_petal, side_petal,
    petal_width_azimuth, petal_width_elevation)

    # a = np.zeros((3, 2))
    # a = np.asarray([[30, 20], [25, 15], [10, 40]], )
    # print(dc.modify_matrix(a))

    installation_angles = np.asarray([[30, 20], [25, 15], [10, 40]], dtype='float64')
    diagram_matrix = dc.calculate(installation_angles)
    print(diagram_matrix)


if __name__ == "__main__":
    main()
