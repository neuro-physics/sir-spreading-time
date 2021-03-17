function [fh,axh,labelFileName,theta,fhFDR,cb1,cb2] = plotSpMatrixSurface(s, dataLabel, groupName, dataTitle, colorProp, labelProperties, labelFileName, useFDR, nodeLabel, nodeDataType, joinNodes, sortNodesBy)
    if (nargin < 3) || isempty(groupName)
        groupName = 'TLE';
    end
    if nargin < 4
        dataTitle = [];
    end
    if nargin < 5
        colorProp = [];
    end
    if nargin < 6
        labelProperties = [];
    end
    if (nargin < 7) || isempty(labelFileName)
        if ~isempty(labelProperties)
            if ischar(labelProperties) && strcmpi(labelProperties,'file')
                error('plotSpMatrixSurface:labelFileName','you must provide a file name');
            end
            if ischar(labelProperties) && strcmpi(labelProperties,'print')
                labelFileName = [];
            end
        end
        if isempty(labelProperties) || iscell(labelProperties)
            labelFileName = [];
        end
    end
    if (nargin < 8) || isempty(useFDR)
        useFDR = false; % false, true, or 2; if useFDR == 2, show t-test figures
    end
    if (nargin < 9) || isempty(nodeLabel)
        nodeLabel = ''; % it could be any name in the AAL labels, or a number in 1:N
    end
    if (nargin < 10) || isempty(nodeDataType)
        nodeDataType = 'raw'; % 'raw' or 'ttest'
    end
    if (nargin < 11) || isempty(joinNodes)
        joinNodes = false;
    end
    if (nargin < 12) || isempty(sortNodesBy)
        sortNodesBy = 'lobe';
    end
    if ~isempty(labelFileName)
        labelFileName = CheckAndGetFileName(labelFileName);
    end
    
    if iscell(dataLabel)
        isStdLabel = cellfun(@(x)~isempty(x),strfind(dataLabel,'Std'));
        isTTestLabel = cellfun(@(x)~isempty(x),regexp(dataLabel,'^ttest_'));
        if ~any(isStdLabel)
            isStdLabel = cellfun(@(x)~isempty(x),strfind(dataLabel,'Err'));
        end
        mDataLabel = dataLabel{(~isStdLabel) & (~isTTestLabel)};
        stdDataLabel = dataLabel{isStdLabel};
        if any(isTTestLabel)
            tDataLabel = dataLabel{isTTestLabel};
        else
            tDataLabel = mDataLabel;
        end
    else
        mDataLabel = dataLabel;
        stdDataLabel = [];
        tDataLabel = mDataLabel;
    end
    fp = getDefaultFigureProperties();
    fp.pColors = [hex2rgb({'#33a02c','#6a3d9a'});fp.pColors];
    nT = numel(s.theta);
    theta = s.theta;
    hasTTest = isfield(s.ttest, mDataLabel);
    fh = gobjects(1,nT);
    if useFDR == 2
        fhFDR = gobjects(1,nT);
    else
        fhFDR = [];
    end
    nodeNameList = [];
    [nodeIndex,nLabel] = getNodeIndex(nodeLabel,size(s.controlData.(mDataLabel){1}));
    if (~joinNodes) && (numel(nodeIndex) > 1)
        if allEqual(nLabel)
            joinNodes = true;
        else
            nodeIndex = nodeIndex(1:2);
            nLabel = nLabel(1:2);
            disp('* Reducing it to two nodes to be displayed...');
        end
    end
    if ~isempty(nodeLabel)
        if allEqual(nLabel)
            nodeNameList = joinNodeNames(filterNumberFromLabel(nLabel{1}));
        else
            nodeNameList = joinNodeNames(nLabel);
        end
        nodeLabelFileName = CheckAndGetFileName([nodeNameList,'_',labelFileName]);
    end
    %nSort = sortAALNodes('lr',[],[],aal.labels.(lab));
    [~,~,~,aal,lab] = aalsurfview(zeros(s.N,1));
    [~,nSort,lobeLim] = groupAALNodes(s.N,sortNodesBy,aal);
    if strcmpi(sortNodesBy,'lobe')
        lobeLim(numel(lobeLim)/2) = NaN;
    end
    lobeLim(end)=[];
    purpleGradient = @(n)[linspace(0.7098,0.3020,n)',linspace(0.5804,0.1647,n)',linspace(0.8510,0.4510,n)'];
    redGradient=@(n)[linspace(0.3,1,n)',linspace(0,0.2,n)',linspace(0,0.2,n)']; % 6a3d9a
    cb1 = gobjects(1,nT);
    cb2 = gobjects(1,nT);
    for i = 1:nT
%     i = 4;
        if isempty(nodeLabel)
            if all(isnan(s.controlData.(mDataLabel){i})) && all(isnan(s.patientData.(mDataLabel){i}))
                disp(sprintf('* NOTE: %s has only NaN for theta = %g', mDataLabel, s.theta(i)));
                continue;
            end
        else
            if all(isnan(s.controlData.(mDataLabel){i}(nodeIndex(1),:))) && all(isnan(s.patientData.(mDataLabel){i}(nodeIndex(1),:)))
                disp(sprintf('* NOTE: %s %s has only NaN for theta = %g', nLabel{1}, mDataLabel, s.theta(i)));
                continue;
            end
            if (numel(nodeIndex)>1) && ...
                (all(isnan(s.controlData.(mDataLabel){i}(nodeIndex(2),:))) && all(isnan(s.patientData.(mDataLabel){i}(nodeIndex(2),:))))
                disp(sprintf('* NOTE: %s %s has only NaN for theta = %g', nLabel{2}, mDataLabel, s.theta(i)));
                continue;
            end
        end
        s.controlData.(mDataLabel){i}(isnan(s.controlData.(mDataLabel){i})) = 0;
        s.patientData.(mDataLabel){i}(isnan(s.patientData.(mDataLabel){i})) = 0;
        if isempty(nodeLabel)
            if all(s.controlData.(mDataLabel){i} == 0) && all(s.patientData.(mDataLabel){i} == 0)
                disp(sprintf('* NOTE: %s has only zeros for theta = %g', mDataLabel, s.theta(i)));
                continue;
            end
        else
            if all(s.controlData.(mDataLabel){i}(nodeIndex(1),:) == 0) && all(s.patientData.(mDataLabel){i}(nodeIndex(1),:) == 0)
                disp(sprintf('* NOTE: %s %s has only NaN for theta = %g', nLabel{1}, mDataLabel, s.theta(i)));
                continue;
            end
            if (numel(nodeIndex)>1) && ...
                (all(s.controlData.(mDataLabel){i}(nodeIndex(1),:) == 0) && all(s.patientData.(mDataLabel){i}(nodeIndex(1),:) == 0))
                disp(sprintf('* NOTE: %s %s has only NaN for theta = %g', nLabel{2}, mDataLabel, s.theta(i)));
                continue;
            end
        end
        
        % plotting surfaces
        if isempty(nodeLabel)
            if hasTTest
                hMat = controlsPatientsDiff(s.controlData.(mDataLabel){i}, s.patientData.(mDataLabel){i}, s.ttest.(tDataLabel)(i).h, s.ttest.(tDataLabel)(i).hFDR);
                [fhTemp,axh,cb1(i),~,~,~] = plot1Surface(hMat, ['T-test ', dataTitle], colorProp, 'continuous', true);
            else
                [fhTemp,axh,cb1(i),cb2(i),~,~] = plot2Surface(s.controlData.(mDataLabel){i},s.patientData.(mDataLabel){i},...
                                                            ['Controls: ', dataTitle],[groupName,': ', dataTitle], colorProp, 'continuous');
            end
        else
            if (~joinNodes) && ((numel(nodeIndex)>1) && strcmp(nodeDataType,'raw'))
                nodeDataType = 'ttest';
                disp('* Forcing nodeDataType == ttest because there is more than one node to be displayed');
            end
            if strcmp(nodeDataType,'raw')
                if numel(nodeIndex) == 1
                    nData1 = s.controlData.(mDataLabel){i}(nodeIndex,:);
                    nData2 = s.patientData.(mDataLabel){i}(nodeIndex,:);
                    nnList = nLabel{1};
                else
                    if joinNodes
                        nData1 = mean(s.controlData.(mDataLabel){i}(nodeIndex,:),1,'omitnan');
                        nData2 = mean(s.patientData.(mDataLabel){i}(nodeIndex,:),1,'omitnan');
                        nnList = nodeNameList;
                    else
                        error('plotSpMatrixSurface:nodeLabel','More than one node was found, it can only be viewed using nodeDataType == ttest');
                    end
                end
                [fhTemp,axh,cb1(i),cb2(i),~,~] = plot2Surface(nData1,nData2,...
                                                            [nnList,' Controls: ', dataTitle],[nnList,' ',groupName,': ', dataTitle], colorProp, 'continuous');
            elseif strcmp(nodeDataType,'ttest')
                if joinNodes
                    nData1 = controlsPatientsDiff(mean(s.controlData.(mDataLabel){i}(nodeIndex,:),1,'omitnan'),...
                                                  mean(s.patientData.(mDataLabel){i}(nodeIndex,:),1,'omitnan'),...
                                                  sum(s.ttest.(tDataLabel)(i).h(nodeIndex,:),1),sum(s.ttest.(tDataLabel)(i).hFDR(nodeIndex,:),1));
                    [fhTemp,axh,cb1(i),~,~,~] = plot1Surface(nData1, [nodeNameList,' T-test ', dataTitle], colorProp, 'continuous', true);
                else
                    nData1 = controlsPatientsDiff(s.controlData.(mDataLabel){i}(nodeIndex(1),:),s.patientData.(mDataLabel){i}(nodeIndex(1),:),...
                                                  s.ttest.(tDataLabel)(i).h(nodeIndex(1),:),s.ttest.(tDataLabel)(i).hFDR(nodeIndex(1),:));
                    if numel(nodeIndex) == 1
                        [fhTemp,axh,cb1(i),~,~,~] = plot1Surface(nData1, [nLabel{1},' T-test ', dataTitle], colorProp, 'continuous', true);
                    else
                        nData2 = controlsPatientsDiff(s.controlData.(mDataLabel){i}(nodeIndex(2),:),s.patientData.(mDataLabel){i}(nodeIndex(2),:),...
                                                      s.ttest.(tDataLabel)(i).h(nodeIndex(2),:),s.ttest.(tDataLabel)(i).hFDR(nodeIndex(2),:));
                        [fhTemp,axh,cb1(i),cb2(i),~,~] = plot2Surface(nData1,nData2,...
                                                                    [nLabel{1},' ', dataTitle],[nLabel{2},' ', dataTitle], colorProp, 'continuous');
                    end
                end
            else
                error('plotSpMatrixSurface:nodeDataType','wrong nodeDataType; it can only be raw or ttest');
            end
        end % end isempty(nodeLabel)
        fhTemp = resizeFig(fhTemp,[fhTemp.Position(3),fhTemp.Position(4)*1.5]);
        
        nodes = 1:s.N;
        nCurves = 0;
        if isempty(nodeLabel)
            x = { nodes, nodes };
            legNames = {'Control',groupName};
            nCurves = 2;
            if hasTTest
                y = { zeros(size(nodes)), (s.patientData.(mDataLabel){i}(nSort)-s.controlData.(mDataLabel){i}(nSort)) };
                %hy = reshape(s.ttest.(dataLabel)(i).h,size(y{2})).*y{2};
                hy = s.ttest.(tDataLabel)(i).h(nSort);
                hx = nodes(hy>0);
                hy = hy(hy>0).*max(y{2}) + diff(minmax(y{2}(:)'))/10;
                %hy = hy.*max(y{2})+diff(minmax(y{2}(:)'))/10;
                [x,y,legNames] = concatIfAnyData(x,y,legNames,y{2},nodes,s.ttest.(tDataLabel)(i).h(nSort),'T-test');
                [x,y,legNames] = concatIfAnyData(x,y,legNames,y{2},nodes,s.ttest.(tDataLabel)(i).hFDR(nSort),'FDR');
            else
                y = { s.controlData.(mDataLabel){i}(nSort), s.patientData.(mDataLabel){i}(nSort) };
            end
            yErr = cell(size(x));
            if ~isempty(stdDataLabel)
                yErr = cell(size(x));
                yErr{1} = s.controlData.(stdDataLabel){i}(nSort);
                yErr{2} = s.patientData.(stdDataLabel){i}(nSort);
            end
        else
            x = { nodes, nodes };
            if joinNodes
                % yy1 = mean(s.patientData.(mDataLabel){i}(nodeIndex,nSort),1,'omitnan') - mean(s.controlData.(mDataLabel){i}(nodeIndex,nSort),1,'omitnan');
                % y = { zeros(size(nodes)), yy1 };
                % legNames = { 'Control', [nodeNameList,' ',groupName] };
                legNames = [ 'Control', appendStr(nLabel,[' ',groupName]) ];
                x = cellfun(@(arg)nodes,cell(1,numel(nodeIndex) + 1),'UniformOutput',false);
                y = cell(1,numel(nodeIndex) + 1);
                y{1} = zeros(size(nodes));
                y(2:end) = cellfun(@(ind)(s.patientData.(mDataLabel){i}(ind(1),nSort) - s.controlData.(mDataLabel){i}(ind(1),nSort)),...
                                   num2cell(nodeIndex),'UniformOutput',false);
                nCurves = numel(y);
            else
                yy1 = s.patientData.(mDataLabel){i}(nodeIndex(1),nSort)-s.controlData.(mDataLabel){i}(nodeIndex(1),nSort);
                y = { zeros(size(nodes)), yy1 };
                legNames = { 'Control', [nLabel{1},' ',groupName] };
                nCurves = 2;
                if numel(nodeIndex) > 1
                    yy1 = s.patientData.(mDataLabel){i}(nodeIndex(2),nSort)-s.controlData.(mDataLabel){i}(nodeIndex(2),nSort);
                    x = [ x, nodes ];
                    y = [ y, yy1 ];
                    legNames = [legNames,[nLabel{2},' ',groupName]];
                    nCurves = 3;
                end
            end
            %hy{1} = reshape(s.ttest.(dataLabel)(i).h(nodeIndex(1),:),size(y{2})).*y{2};
            if joinNodes
                hy{1} = sum(s.ttest.(tDataLabel)(i).h(nodeIndex,nSort),1);
                hy{1}(hy{1}>0)=1;
                nnList = nodeNameList;
            else
                hy{1} = s.ttest.(tDataLabel)(i).h(nodeIndex(1),nSort);
                nnList = nLabel{1};
            end
            hx{1} = nodes(hy{1}>0);
            hy{1} = hy{1}(hy{1}>0);
            [x,y,legNames] = concatIfAnyData(x,y,legNames,y{2},hx{1},hy{1},[nnList,' T-test']);
            hy{1} = hy{1}.*max(y{2}) + diff(minmax(y{2}(:)'))/10;
            % [x,y,legNames] = concatIfAnyData(x,y,legNames,y{2},nodes,s.ttest.(dataLabel)(i).h(nodeIndex(1),:),[nnList,' T-test']);
            if (~joinNodes) && (numel(nodeIndex) > 1)
                hy{2} = s.ttest.(tDataLabel)(i).h(nodeIndex(2),nSort);
                hx{2} = nodes(hy{2}>0);
                hy{2} = hy{2}(hy{2}>0);
                [x,y,legNames] = concatIfAnyData(x,y,legNames,y{2},hx{2},hy{2},[nLabel{2},' T-test']);
%                 hy{2} = reshape(s.ttest.(dataLabel)(i).h(nodeIndex(2),:),size(y{2})).*y{2};
                hy{2} = hy{2}.*max(y{2}) + diff(minmax(y{2}(:)'))/10;
            end
            if joinNodes
                hMat1 = sum(s.ttest.(tDataLabel)(i).hFDR(nodeIndex,nSort),1);
                hMat1(hMat1>0)=1;
                [x,y,legNames] = concatIfAnyData(x,y,legNames,y{2},nodes(hMat1>0),hMat1(hMat1>0),[nodeNameList,' FDR']);
            else
                hMat1 = s.ttest.(tDataLabel)(i).hFDR(nodeIndex(1),nSort);
                [x,y,legNames] = concatIfAnyData(x,y,legNames,y{2},nodes(hMat1>0),hMat1(hMat1>0),[nLabel{1},' FDR']);
            end
            if (~joinNodes) && (numel(nodeIndex) > 1)
                hMat1 = s.ttest.(tDataLabel)(i).hFDR(nodeIndex(2),nSort);
                [x,y,legNames] = concatIfAnyData(x,y,legNames,y{2},nodes(hMat1>0),hMat1(hMat1>0),[nLabel{2},' FDR']);
            end
            
            yErr = cell(size(x));
            if ~isempty(stdDataLabel)
                if joinNodes
                    yErr{1} = max(s.controlData.(stdDataLabel){i}(nodeIndex,nSort)); % max std dev for each node across each nodeIndex line
                    yErr(2:nCurves) = cellfun(@(ind)s.patientData.(stdDataLabel){i}(ind(1),nSort),num2cell(nodeIndex),'UniformOutput',false);
                else
                    yErr{1} = s.controlData.(stdDataLabel){i}(nodeIndex(1),nSort);
                    yErr{2} = s.patientData.(stdDataLabel){i}(nodeIndex(1),nSort);
                    if numel(nodeIndex)>1
                        yErr{3} = s.patientData.(stdDataLabel){i}(nodeIndex(2),nSort);
                    end
                end
            end
        end % if isempty(nodeLabel)

        if isempty(nodeLabel)
            if hasTTest
                axPos = [fp.lMargin,(fp.bMargin+fp.hAx)/1.5,(2*fp.wAx+fp.lMargin),fp.hAx/2.5];
            else
                axPos = [fp.lMargin,(fp.bMargin+fp.hAx)/1.37,(2*fp.wAx+fp.lMargin),fp.hAx/3];
            end
        else
            axPos = [fp.lMargin,(fp.bMargin+fp.hAx)/1.37,(2*fp.wAx+fp.lMargin),fp.hAx/3];
            if strcmp(nodeDataType,'ttest') && (numel(nodeIndex)==1)
                axPos = [fp.lMargin,(fp.bMargin+fp.hAx)/1.5,(2*fp.wAx+fp.lMargin),fp.hAx/2.5];
            end
        end
        figure(fhTemp);
        ax = axes('Position', axPos);
%         ax = axes(fhTemp, 'Position', axPos);

        % ppLin = { '-' };
        % ppSym = [fp.pSymbols(1:2),'*o'];
        % ppCol = [fp.pColors(1:2,:);0,0,0;1,0,0];
        % if (~joinNodes) && (~isempty(nodeLabel) && (numel(nodeIndex) > 1))
        %     ppSym = [fp.pSymbols(1:4),'*osd'];
        %     ppCol = [fp.pColors(1:4,:);0,0,0;1,0,0;0,0,1;1,0,1];
        % end
        %ppLin = [{ '-' },num2cell(repmat('n',1,nCurves-1)),num2cell('nnnn')];
        ppLin = [{ '-' },repeatToComplete({'-','--',':','-.'},nCurves-1),num2cell('nnnn')];
        ppSym = ['nn',repeatToComplete('osv><phx',nCurves-2),'*o+s'];
        %ppCol = [fp.pColors(1,:); redGradient(nCurves-1); 0,0,0;1,0,0;0,0,1;1,0,1];
        ppCol = [fp.pColors(1,:); purpleGradient(nCurves-1); 0,0,0;1,0,0;0,0,1;1,0,1];
        if (~hasTTest) && isempty(nodeLabel)
            ppLin = { ':' };
            ppSym = 'nn';
            ppCol = fp.pColors(1:2,:);
        end
        % ppSym = ['n',repmat(fp.pSymbols(2),1,nCurves-1),'*osd'];repeatToComplete(x,N)
        % ppCol = [fp.pColors(1,:); repmat(fp.pColors(2,:),nCurves-1,1); 0,0,0;1,0,0;0,0,1;1,0,1];
        ps = getPlotStruct(x,y,yErr,'Node, $n$', dataTitle, 'linear', 'linear', '', legNames, 1, '');
        kleg = find(cellfun(@(x)~isempty(x),strfind(ps.legend,'FDR')) | cellfun(@(x)~isempty(x),strfind(ps.legend,'T-test')));
        for kk=1:numel(kleg),ps.curves(kleg(kk)).showLegend = 0; end
        plotPlotStruct(ax, ps, ppLin, [], ppSym, ppCol, ...
            {'LineWidth', fp.pLineWidth, 'MarkerSize', fp.pPointSize, 'MarkerFaceColor', 'none'},... % plot properties
            {'ShowErrorBar', 'on', 'Color', 'auto', 'Fill', 'on', 'LineStyle', 'none'},... % error properties
            {'Box', 'on', 'Layer', 'top', 'XLim', [(nodes(1)-1),(nodes(end)+1)]},... % axis properties
            {'Location', 'northoutside', 'Orientation', 'horizontal', 'FontSize', 8, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
            {'FontSize', 12}); % label properties
%             {'Location', 'southeastoutside', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
%         hold(ax,'on')
%         for llk = 1:numel(lobeLim)
%             line(ax, [lobeLim(llk),lobeLim(llk)]+0.5, ax.YLim, 'LineStyle', ':', 'Color', 'k', 'LineWidth', 0.5, 'HandleVisibility', 'off');
%         end
%         line(ax, [s.N/2,s.N/2]+0.5, ax.YLim, 'LineStyle', '--', 'Color', 'k', 'LineWidth', 1, 'HandleVisibility', 'off');
%         hold(ax,'off')
        
        sortedAALLabels = aal.labels.(lab)(nSort);
        if isempty(nodeLabel)
            if hasTTest
                tx = writeTextLabels2Surf(sortedAALLabels(hx), hx, hy, 'T-test', [], [], [], [], dataTitle, {'k'}, labelProperties, labelFileName, fhTemp.Number, s.N, s.theta(i));

                if useFDR == 2
                    fhFDR(i) = plotTTestFigure(s.ttest.(tDataLabel)(i),nSort);
                    figure(fhTemp);
                end
            else
                kC = find(s.controlData.(mDataLabel){i}(nSort) > 0);
                kP = find(s.patientData.(mDataLabel){i}(nSort) > 0);
                tx = writeTextLabels2Surf(sortedAALLabels(kC), kC, s.controlData.(mDataLabel){i}(kC), 'Controls',...
                                          sortedAALLabels(kP), kP, s.patientData.(mDataLabel){i}(kP), groupName,...
                                          dataTitle, fp.pColors(1:2,:), labelProperties, labelFileName, fhTemp.Number, s.N, s.theta(i));
            end % hasTTest
        else
            if joinNodes
                tx = writeTextLabels2Surf(sortedAALLabels(hx{1}), hx{1}, hy{1}, [nodeNameList,' T-test'], [], [], [], [], dataTitle, {'k'}, labelProperties, nodeLabelFileName, fhTemp.Number, s.N, s.theta(i));
            else
                if numel(nodeIndex) == 1
                    tx = writeTextLabels2Surf(sortedAALLabels(hx{1}), hx{1}, hy{1}, [nLabel{1},' T-test'], [], [], [], [], dataTitle, {'k'}, labelProperties, nodeLabelFileName, fhTemp.Number, s.N, s.theta(i));
                else
                    tx = writeTextLabels2Surf(sortedAALLabels(hx{1}), hx{1}, hy{1}, [nLabel{1},' T-test'],...
                                              sortedAALLabels(hx{2}), hx{2}, hy{2}, [nLabel{2},' T-test'], ...
                                              dataTitle, {'k','k'}, labelProperties, nodeLabelFileName, fhTemp.Number, s.N, s.theta(i));
                end
            end
        end % isempty(nodeLabel)

        anh = annotation(fhTemp, 'textbox', [0.8,0.1,0.01,0.01], 'String', ['$\theta=',thetaValToTxt(s.theta(i)),'$'], 'Interpreter', 'latex', 'FitBoxToText', 'on', 'FontSize', 12, 'LineStyle', 'none');
        fh(i) = fhTemp;
        plotVerticalLines(ax,lobeLim+0.5,'LineStyle',':','Color','k','LineWidth',0.5,'HandleVisibility','off');
        if strcmpi(sortNodesBy,'lobe')
            plotVerticalLines(ax,s.N/2+0.5,'LineStyle','--','Color','k','LineWidth',1.1,'HandleVisibility','off');
        end
        drawnow
    end % for loop end
    if ~isempty(nodeLabel)
        labelFileName = { labelFileName, nodeLabelFileName };
    end
    k = [];
    for i = 1:nT
        if strcmpi(class(fh(i)),'matlab.graphics.GraphicsPlaceholder')
            k(end+1) = i;
        end
    end
    fh(k) = [];
    theta(k) = [];
    if useFDR == 2
        fhFDR(k) = [];
    end
    if exist('axh','var') ~= 1
        axh = gobjects(1);
    end
end

function d = controlsPatientsDiff(c,p,h,hFDR)
    h(h>0)=1;
    hFDR(hFDR>0)=1;
    d = reshape(p - c,size(h)).*h;
    d(d>0) = 1;
    d(d<0) = -1;
    d((hFDR==1) & (d>0)) = 2;
    d((hFDR==1) & (d<0)) = -2;
end

function n = joinNodeNames(nn)
    if ischar(nn)
        nn = { nn };
    end
    n = '';
    for i = 1:numel(nn)
        m = strjoin(regexp(nn{i},'[A-Z0-9]{1}([a-z]{0,2}|\d*)','match'),'');
        n = [ n, '-', m ];
    end
    n(1)=[];
end

function [x,y,legNames,hasData] = concatIfAnyData(x,y,legNames,yScal,sx,sy,sName)
    if iscell(sy)
        hasData = zeros(size(sy));
        for i = 1:numel(sy)
            [x,y,legNames,hasData(i)] = concatIfAnyData_single(x,y,legNames,yScal,sx{i},sy{i},sName{i});
        end
    else
        [x,y,legNames,hasData] = concatIfAnyData_single(x,y,legNames,yScal,sx,sy,sName);
    end
end

function [x,y,legNames,hasData] = concatIfAnyData_single(x,y,legNames,yScal,sx,sy,sName)
    hy = sy;
    hx = sx(hy>0);
    hy = hy(hy>0);
    hasData = ~isempty(hx);
    if hasData
        x = [x,hx];
        y = [y,hy];
        y{end} = y{end}.*max(yScal)+diff(minmax(yScal(:)'))/10;
        %hy = y{end};
        legNames = [legNames,sName];
    end
end

function [n,nn] = getNodeIndex(nLabel,szData)
    if isempty(nLabel)
        n = [];
        nn = [];
        return;
    end
    if any(numel(nLabel) == szData)
        n = 1:numel(nLabel);
        nn = strrep(nLabel,'_','-');
        return;
    end
    N = max(szData);
    [~,~,~,aal,lab]=aalsurfview(zeros(N,1));
    if ischar(nLabel)
        n = find(~cellfun(@isempty,strfind(aal.labels.(lab),nLabel)));
        nn = strrep(aal.labels.(lab)(n),'_','-');
    else
        if iscell(nLabel)
            n = zeros(size(nLabel));
            nn = cell(size(nLabel));
            for i = 1:numel(n)
                temp = find(~cellfun(@isempty,strfind(aal.labels.(lab),nLabel{i})));
                if isempty(temp)
                else
                    n(i) = temp;
                    nn{i} = strrep(aal.labels.(lab){n(i)},'_','-');
                end
            end
        else
            n = nLabel;
            nn = strrep(aal.labels.(lab)(n),'_','-');
        end
    end
end

function [colorArr,colorLim1,colorLim2]=getColorProperties(colorProp,s1,s2,useSameColorLim)
    if isempty(colorProp)
        colorArr = hot;
    elseif ismatrix(colorProp) && (size(colorProp,2) == 3)
        colorArr = colorProp;
    elseif iscell(colorProp)
        colorArr = getParamValue('ColorArr',colorProp,false);
    else
        error('plotSpMatrixSurface:colorProp','unrecognized format for colorProp param');
    end
    colorLim1 = getParamValue('ColorLim',colorProp,false);
    if isempty(colorLim1)
        colorLim1 = getParamValue('ColorLim1',colorProp,false);
        if isempty(colorLim1)
            colorLim1 = getColorLim(s1,colorArr);
        end
    end
    if isempty(s2)
        colorLim2 = colorLim1;
    else
        colorLim2 = getParamValue('ColorLim2',colorProp,false);
        if isempty(colorLim2)
            colorLim2 = getColorLim(s2,colorArr);
        end
        if useSameColorLim
            colorLim1 = [ min(colorLim1(1),colorLim2(1)), max(colorLim1(2),colorLim2(2)) ];
            colorLim2 = colorLim1;
        end
    end
end

function [fh,axh,cb1,cb2,aal,lab] = plot1Surface(s, dataTitle, colorProp, colorMode, showSymbolLegend)
%     colorLim = double(minmax(s(:)'));
%     if colorLim(1) == colorLim(2)
%         colorLim = [-1,1];
%     end
    [colorArr,colorLim]=getColorProperties(colorProp,s,[],0);
    [fh,axh,cb1,aal,lab] = aalsurfview(s, dataTitle, colorArr, colorMode, colorLim, showSymbolLegend);
    cb2 = [];
end

function [fh,axh,cb1,cb2,aal,lab] = plot2Surface(s1, s2, data1Title, data2Title, colorProp, colorMode, useSameColorLim)
%     cl1 = minmax(s1(:)');
%     cl1(isinf(cl1)) = NaN;
%     cl2 = minmax(s2(:)');
%     cl2(isinf(cl2)) = NaN;
%     colorLim = [ min(cl1(1),cl2(1)), max(cl1(2),cl2(2)) ];
%     if colorLim(1) == colorLim(2)
%         colorLim = [0,1];
%     end
    if (nargin < 7) || isempty(useSameColorLim)
        useSameColorLim = true;
    end
    [colorArr,cl1,cl2] = getColorProperties(colorProp,s1,s2,useSameColorLim);
    [fh,~,cb1,~,~]       = aalsurfview(s1, data1Title, colorArr, colorMode, cl1, true);
    [fh,axh,cb2,aal,lab] = aalsurfview(s2, data2Title, colorArr, colorMode, cl2, false, fh, [0,1]);
end

function cl = getColorLim(s,colorArr)
    if any(isinf(s))
        sTemp = s;
        ms = mean(s(:));
        sTemp(isinf(sTemp))=ms;
        mmTemp = minmax(sTemp(:)');
        s(isinf(s)&(s<0)) = mmTemp(1);
        s(isinf(s)&(s>0)) = mmTemp(2);
    end
    cl = minmax(s(:)');
    if cl(1) == cl(2)
        if cl(1) > 0
            cl = [0,cl(1)];
        elseif cl(1) < 0
            cl = [cl(1),0];
        else
            if (size(colorArr,1) <= 5)
                cl = [-2,2];
            else
                cl = [0,1];
            end
        end
    else
%         k = findDarkestColorIndex(colorArr);
%         n = size(colorArr,1);
        u = unique(s(:));
        if any(numel(u) == [2,3,4,5]) && (size(colorArr,1) <= 5)
            if cl(1) == 0
                cl(1) = -cl(2);%((1-k)/n)*cl(2);
            elseif cl(2) == 0
                cl(2) = -cl(1);%((n-k)/n)*abs(cl(1));
            end
        end
        if (abs(cl(1)) == 1) && (abs(cl(2)) == 1)
            cl = [-2,2];
        end
    end
end

function k = findDarkestColorIndex(c)
    [~,k] = min(sqrt(sum(c.^2,2)));
end

function fh = plotTTestFigure(s,nSort)
    n = 1:numel(s.h);

    h = s.h(nSort);
    hFDR = s.hFDR(nSort);
    tt = s.t(nSort);
    
    x = { n(h>0), n(hFDR>0), n };
    y = { h(h>0), hFDR(hFDR>0), tt };
    legText = { ['$p\leq',num2str(s.alpha),'$'], 'FDR', '$t$' };

    if isempty(x)
        fh = gobjects;
    else
        fp = getDefaultFigureProperties();
        fh = figure('Position', [fp.x0Fig,fp.y0Fig,fp.wFig,fp.hFig]);
        ax = axes('Position', [fp.lMargin,fp.bMargin,(2*fp.wAx+fp.lMargin),fp.hAx]);
%         ax = axes(fh, 'Position', [fp.lMargin,fp.bMargin,(2*fp.wAx+fp.lMargin),fp.hAx]);

        pLines = {'n','n','-'};
        pSymbols = '*on';
        pColors = [0,0,1;1,0,0;0,0,0];
        
        k = cellfun(@isempty,y);
        x(k) = [];
        y(k) = [];
        legText(k) = [];
        pLines(k) = [];
        pSymbols(k) = [];
        pColors(k,:) = [];
        
        ps = getPlotStruct(x,y,cell(size(x)),'Node, $n$', '$t$-values', 'linear', 'linear', '', legText, 1, '');

        plotPlotStruct(ax, ps, pLines, [], pSymbols, pColors, ...
            {'LineWidth', fp.pLineWidth, 'MarkerSize', fp.pPointSize, 'MarkerFaceColor', 'none'},... % plot properties
            {'ShowErrorBar', 'off'},... % error properties
            {'Box', 'on', 'Layer', 'top', 'XLim', [(n(1)-1),(n(end)+1)]},... % axis properties
            {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
            {'FontSize', 12}); % label properties
        drawnow
    end
end

function r = writeTextLabels2Surf(lab1, x1, y1, data1Title, lab2, x2, y2, data2Title, dataTitle, color, labProp, labFileName, figNum, N, theta)
    if isempty(labProp) || ~ischar(labProp)
        if ~iscell(color)
            if ischar(color)
                if numel(color) < 2
                    color = [ color,color ];
                end
                color = { color(1), color(2) };
            else
                scol = size(color,1);
                if scol < 2
                    color = [ color;color ];
                end
                color = { color(1,:), color(2,:) };
            end
        end
        r = writeTextLabels(lab1, x1, y1, color{1}, labProp);
        if ~isempty(lab2)
            r = writeTextLabels(lab2, x2, y2, color{2}, labProp);
        end
    else
        %writeNodeLabels(labelProperties, str,);
        cLab = lab1;
        cLab = sprintf('%s, ', cLab{:});
        if ~isempty(lab2)
            pLab = lab2;
            pLab = sprintf('%s, ', pLab{:});
        end

        str = '---\n';
        str = [str, 'Labels for Figure ', num2str(figNum),'\n'];
        str = [str, '* ', dataTitle, ', N=', num2str(N), ', theta=', num2str(theta), '\n'];
        str = [str, '  * ', data1Title, ': ', cLab(1:(end-2)), '\n'];
        if ~isempty(lab2)
            str = [str, '  * ', data2Title, ': ', pLab(1:(end-2)), '\n'];
        end
        str = [str, '---\n'];

        r=writeTextLabelsFile(str, labFileName, labProp);
    end
end

function fileName = writeTextLabelsFile(txt, fileName, labProp)
    if strcmpi(labProp, 'print')
        disp(sprintf(txt));
    elseif strcmpi(labProp, 'file')
        fid = fopen(fileName, 'a');
%         fprintf(fid, '%s', sprintf(strrep(txt,'\','\\')));
        fprintf(fid, replaceLatexBackslash(txt));
%         disp(txt)
        fclose(fid);
    else
        error('plotSpMatrixSurface:labelProperties','unrecognized text input to labelProperties');
    end
end

function tx=writeTextLabels(lab, x, y, color, labProp)
    tx=[];
    for i = 1:numel(x)
        if iscell(labProp)
            tx(end+1) = text(x(i), y(i), lab{i}, 'Interpreter', 'none', 'Rotation', 90, 'Color', color, 'HorizontalAlignment', 'right', labProp{:});
        else
            tx(end+1) = text(x(i), y(i), lab{i}, 'Interpreter', 'none', 'Rotation', 90, 'Color', color, 'HorizontalAlignment', 'right');
        end
    end
end

function r = allEqual(v)
    if isnumeric(v) || ischar(v)
        r = all(v == v(1));
    else
        r = all(strcmpi(filterNumberFromLabel(v),filterNumberFromLabel(v{1})));
    end
end

function l = filterNumberFromLabel(lab)
    l = regexprep(lab,'[_-]\d+$','');
end

function [v,c] = getParamValue(par,c,del)
    if (nargin < 3) || isempty(del)
        del = false;
    end
    k = find(strcmpi(c,par));
    if isempty(k)
        v = [];
        return;
    end
    if k == numel(c)
        error(['missing parameter value for ', par]);
    end
    v = c{k+1};
    if del
        c(k:(k+1)) = [];
    end
end
