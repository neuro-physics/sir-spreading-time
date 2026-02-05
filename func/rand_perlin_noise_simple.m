function im = rand_perlin_noise_simple(nrows,ncols,output_rand_range)
% https://stackoverflow.com/questions/7347111/generate-procedural-perlin-noise-in-matlab
% output is nrows X ncols matrix
% output_rand_range -> [min,max] the values in the output are rescaled to this range
    if (nargin < 3) || isempty(output_rand_range)
        output_rand_range = [];
    end
    im     = zeros(nrows,ncols);
    [m, n] = size(im);
    i      = 0;
    w      = sqrt(m*n);
    while w > 3
        i  = i + 1;
        %d = interp2(randn(n, m), i-1, 'spline');
        d  = interp2(randn(ceil((m-1)/(2^(i-1))+1),ceil((n-1)/(2^(i-1))+1)), i-1, 'spline');
        im = im + i * d(1:m, 1:n);
        w  = w - ceil(w/2 - 1);
    end
    if ~isempty(output_rand_range)
        assert(numel(output_rand_range)==2,'output_rand_range must be [min,max]')
        mm_im = minmax(im(:)');
        X1 = mm_im(1);
        X2 = mm_im(2);
        Y1 = output_rand_range(1);
        Y2 = output_rand_range(2);
        a  = (Y2 - Y1) / (X2 - X1);
        b  = Y1 - a * X1;
        im = a.*im + b;
    end
end