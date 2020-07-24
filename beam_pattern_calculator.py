import beam_pattern_calculator_bind
import numpy as np

class BeamPatternCalculator(beam_pattern_calculator_bind.BeamPatternCalculator):
    def __init__(self, start_azimuth, end_azimuth,
            start_elevation, end_elevation,
            n_azimuths, n_elevations,
            main_lobe, side_lobe,
            lobe_width_azimuth, lobe_width_elevation):
            if not isinstance(start_azimuth, (int, float)):
                raise ValueError('start_azimuth must be int/float')
            if not isinstance(end_azimuth, (int, float)):
                raise ValueError('end_azimuth must be int/float')
            if not isinstance(start_elevation, (int, float)):
                raise ValueError('start_elevation must be int/float')
            if not isinstance(end_elevation, (int, float)):
                raise ValueError('end_elevation must be int/float')
            if not isinstance(n_azimuths, int):
                raise ValueError('n_azimuths must be int')
            if not isinstance(n_elevations, int):
                raise ValueError('n_elevations must be int')
            if not isinstance(main_lobe, (int, float)):
                raise ValueError('main_lobe must be int/float')
            if not isinstance(side_lobe, (int, float)):
                raise ValueError('side_lobe must be int/float')
            if not isinstance(lobe_width_azimuth, (int, float)):
                raise ValueError('lobe_width_azimuth must be int/float')
            if not isinstance(lobe_width_elevation, (int, float)):
                raise ValueError('lobe_width_elevation must be int/float')

            super().__init__(start_azimuth, end_azimuth,
            start_elevation, end_elevation,
            n_azimuths, n_elevations,
            main_lobe, side_lobe,
            lobe_width_azimuth, lobe_width_elevation)

    def calculate(self, installation_angles):
        if not isinstance(installation_angles, np.ndarray):
            raise ValueError('installation_angles must be np.ndarray')
        if len(installation_angles.shape) != 2:
            raise ValueError('installation_angles must be 2d matrix')

        matrix_list = super().calculate(installation_angles)
        return np.asarray(matrix_list)
